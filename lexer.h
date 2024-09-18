#pragma once
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
  std::vector<Token> tokens;

  char next();

 public:
  Lexer();
  ~Lexer();

  std::vector<Token> get_tokens() const { return tokens; }

  /**
   * Feeds to the lexer a code line.
   * 
   * Args:
   *  (std::string) code_line: The line of code to tokenize.
   * 
   * Returns:
   *  True: If lexing OK.
   *  False: If there's a problem.
   * 
   * TODO: Implement this
   */
  bool feed(std::string code_line);
  bool feed(std::ifstream* source_file);
};
