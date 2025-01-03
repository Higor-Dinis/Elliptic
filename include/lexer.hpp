// Copyright [2025] <Higor Dinis>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#pragma once
#include <bits/stdc++.h>

#include <fstream>
#include <string>
#include <vector>

#include "tokens.hpp"

/**
 * @class Lexer
 * @brief A class to tokenize source code.
 * 
 * The Lexer class is responsible for converting a string of source code into a vector of tokens.
 * It maintains the current character index, the actual character being processed, the source code,
 * and the list of tokens generated. It also has a list of keywords to recognize specific tokens.
 * 
 * @note The class provides methods to feed code lines or files to the lexer and retrieve the generated tokens.
 */
class Lexer {
 private:
  int character_index = -1;
  char actual_character;
  std::string source_code;
  std::vector<Token> tokens;
  std::vector<std::string> keywords = {"exit"};

  char next();

  char peek(int i);

  char peek();

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
   * @note This method is used to tokenize a single line of code.
   */
  bool feed(std::string code_line);

  
  /**
   * Feeds to the lexer a source file.
   * 
   * Args:
   *  (std::ifstream*) source_file: The source file to tokenize.
   * 
   * Returns:
   *  True: If lexing OK.
   *  False: If there's a problem.
   * 
   * @note This method is used to tokenize a entire file of code.
   */
  bool feed(std::ifstream* source_file);
};
