#include <fstream>
#include <string>
#include <vector>
#include "tokens.h"

class Lexer {
 private:
  int actual_character;
  std::string source_code;
  std::vector<Tokens::Token> tokens;

  char ahead(int i);

 public:
  Lexer();
  ~Lexer();
  int feed(std::string code_line);
  int feed(std::ifstream* source_file);
};

Lexer::Lexer() {}

Lexer::~Lexer() {}

char Lexer::ahead(int i) {
  /*
  * Look ahead a given number of characters
  * */
  return source_code.at(actual_character + i);
}

int Lexer::feed(std::string code_line) {
  return 0;
}

int Lexer::feed(std::ifstream* source_file) {
  if (source_file->is_open()) {
    std::string buffer;

    *source_file >> source_code;
    std::cout << source_code << std::endl;
    for (size_t i = 0; i < source_code.length(); i++)
    {
      char actual_character = source_code.at(i);
      if (actual_character == '\n') {
        continue;
      } 
      if (actual_character == '(') {
        if (buffer == "exit") {
          buffer.clear();
          Tokens::Token token_exit;
          token_exit.type = Tokens::TokenType::EXIT;
          token_exit.token_args.push_back((int)source_code.at(i += 1) - 48);
          tokens.push_back(token_exit);
        }
      }
      if (isalnum(actual_character)) {
        buffer += actual_character;
      }
    }
  } else {
    return 1;
  }
  return 0;
}