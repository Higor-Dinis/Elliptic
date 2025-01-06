// Copyright [2025] <Higor Dinis>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "lexer.hpp"

#include <iostream>
#include <string>

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
  try {
    return source_code.at(character_index + 1);
  } catch (const std::out_of_range) {
    return '\0';
  }
}

void Lexer::handleWhitespace() {
  while (isspace(peek()) && peek() != '\0') {
    actual_character = next();
  }
}

void Lexer::handleNewLine() {
  while (peek() == '\n') {
    actual_character = next();
  }
}

void Lexer::handleDecLiteral() {
  buffer += actual_character;

  while (isdigit(peek()) && peek() != '\0') {
    buffer += next();
  }
  next();

  tokens.push_back({TokenType::DEC_LIT, buffer});
  buffer.clear();
}

bool Lexer::isKeyword(const std::string word) {
  return std::find(keywords.begin(), keywords.end(), word) != keywords.end();
}

void Lexer::handleIdentifier() {
  buffer += actual_character;

  while (isalnum(peek())) {
    buffer += next();
  }

  if (isKeyword(buffer)) {
    tokens.push_back({TokenType::KEYWORD, buffer});
  } else {
    tokens.push_back({TokenType::IDENTIFIER, buffer});
  }

  buffer.clear();
}

bool Lexer::feed(std::ifstream* source_file) {
  if (!source_file->is_open()) {
    return false;
  }

  source_code.assign((std::istreambuf_iterator<char>(*source_file)),
                     std::istreambuf_iterator<char>());
  std::cout << source_code << std::endl;

  next();

  while (character_index < source_code.length()) {
    switch (actual_character) {
      case '\n':
        handleNewLine();
        break;
      case '(': {
        tokens.push_back({TokenType::OPN_PAR, "("});
        buffer.clear();
      } break;
      case ')': {
        if (!buffer.empty()) {
          tokens.push_back({TokenType::IDENTIFIER, buffer});
        }
        tokens.push_back({TokenType::CLS_PAR, ")"});
        buffer.clear();
      } break;
      case '=': {
        tokens.push_back({TokenType::EQ, "="});
        buffer.clear();
      } break;
      case '+': {
        tokens.push_back({TokenType::PLUS, "+"});
        buffer.clear();
      } break;
      case ' ': {
        handleWhitespace();
      } break;
      default:
        break;
    }

    if (isdigit(actual_character)) {
      handleDecLiteral();
      continue;
    }

    if (isalnum(actual_character) || actual_character == '_') {
      handleIdentifier();
    }

    next();
  }

  tokens.push_back({TokenType::EOF_TOKEN, "EOF"});

  return true;
}
