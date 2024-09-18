#include "lexer.h"

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
    return;
  }

  return actual_character;
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
        while (isdigit(next())) {
          buffer += actual_character;
        }

        Token token_dec_lit;
        token_dec_lit.type = TokenType::DEC_LIT;
        token_dec_lit.value = buffer;
        tokens.push_back(token_dec_lit);
        character_index -= 1;
      }

      if (buffer == "exit") {
        buffer.clear();
        Token token_exit;
        token_exit.type = TokenType::EXIT;
        token_exit.value = "exit";
        tokens.push_back(token_exit);
      }

      actual_character = next();
    }
  } else {
    return false;
  }
  return true;
}