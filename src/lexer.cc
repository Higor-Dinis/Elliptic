#include "lexer.hpp"

Lexer::Lexer() = default;

Lexer::~Lexer() {
  source_code.clear();
  tokens.clear();
}

char Lexer::next() {
  /*
   * Look ahead a given number of characters
   * */
  character_index += 1;

  try {
    actual_character = source_code.at(character_index);
  } catch (const std::out_of_range) {
    return '\0';
  }

  return actual_character;
}

char Lexer::peek(int i) {
  /*
   * Look ahead a given number of characters
   * */
  try {
    return source_code.at(character_index + i);
  } catch (const std::out_of_range) {
    return '\0';
  }
}

char Lexer::peek() {
  /*
   * Look ahead a one character
   * */
  try {
    return source_code.at(character_index + 1);
  } catch (const std::out_of_range) {
    return '\0';
  }
}

// bool Lexer::feed(std::string code_line) { return 0; }

bool Lexer::feed(std::ifstream* source_file) {
  if (source_file->is_open()) {
    std::string buffer;

    *source_file >> source_code;
    std::cout << source_code << std::endl;

    actual_character = next();
    for (; this->character_index < source_code.length();) {
      // TODO: Refactore this, to reduce complexity.
      switch (actual_character) {
        case '\n':
          buffer.clear();
          continue;
          break;
        case '(': {
          Token token_opn_par;
          token_opn_par.type = TokenType::OPN_PAR;
          token_opn_par.value = "(";
          tokens.push_back(token_opn_par);
          buffer.clear();
        } break;
        case ')': {
          Token token_cls_par;
          token_cls_par.type = TokenType::CLS_PAR;
          token_cls_par.value = ")";
          tokens.push_back(token_cls_par);
          buffer.clear();
        } break;
        default:
          if (isalnum(actual_character)) {
            buffer += actual_character;
          };
          break;
      };

      if (isdigit(actual_character)) {
        while (isdigit(peek())) {
          buffer += next();
        }

        Token token_dec_lit;
        token_dec_lit.type = TokenType::DEC_LIT;
        token_dec_lit.value = buffer;
        tokens.push_back(token_dec_lit);
      }

      if (std::find(keywords.begin(), keywords.end(), buffer) !=
          keywords.end()) {
        Token token_keyword;
        token_keyword.type = TokenType::KEYWORD;
        token_keyword.value = buffer;

        tokens.push_back(token_keyword);
        buffer.clear();
      }

      actual_character = next();
    }
  } else {
    return false;
  }
  return true;
}