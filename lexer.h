#include <bits/stdc++.h>

#include <fstream>
#include <string>
#include <vector>

#include "tokens.h"

class Lexer {
 private:
  int character_index = -1;
  char actual_character;
  std::string source_code;
  std::vector<Tokens::Token> tokens;

  char next();

 public:
  Lexer();
  ~Lexer();
  int feed(std::string code_line);
  int feed(std::ifstream* source_file);
};

Lexer::Lexer() {}

Lexer::~Lexer() {}

char Lexer::next() {
  /*
   * Look ahead a given number of characters
   * */
  character_index += 1;

  try
  {
    actual_character = source_code.at(character_index);
  }
  catch(const std::out_of_range)
  {
    return NULL;
  }
  
  return actual_character;
}

int Lexer::feed(std::string code_line) { return 0; }

int Lexer::feed(std::ifstream* source_file) {
  if (source_file->is_open()) {
    std::string buffer;

    *source_file >> source_code;
    std::cout << source_code << std::endl;

    actual_character = next();
    for (; this->character_index < source_code.length();) {
      switch (actual_character) {
        case '\n':
          buffer.clear();
          continue;
          break;
        case '(': {
          Tokens::Token token_opn_par;
          token_opn_par.type = Tokens::OPN_PAR;
          token_opn_par.value = "(";
          tokens.push_back(token_opn_par);
          buffer.clear();
        } break;
        case ')': {
          Tokens::Token token_cls_par;
          token_cls_par.type = Tokens::CLS_PAR;
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
        while (isdigit(next()))
        {
          buffer += actual_character;
        }

        Tokens::Token token_dec_lit;
        token_dec_lit.type = Tokens::DEC_LIT;
        token_dec_lit.value = buffer;
        tokens.push_back(token_dec_lit);
        character_index -= 1;
      }

      if (buffer == "exit") {
        buffer.clear();
        Tokens::Token token_exit;
        token_exit.type = Tokens::TokenType::EXIT;
        token_exit.value = "exit";
        tokens.push_back(token_exit);
      }

      actual_character = next();
    }
  } else {
    return 1;
  }
  return 0;
}