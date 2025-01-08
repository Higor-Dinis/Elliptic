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

#include "scanner.hpp"

Scanner::Scanner(std::ifstream* source_file) {
  this->source_file = source_file;
  this->character_index = -1;
}

Scanner::Scanner(std::string source_code) {
  this->source_code = source_code;
  this->character_index = -1;
}

char Scanner::get_current_char() { return current_character; }

char Scanner::consume_char() {
  character_index += 1;
  int character;

  if (!source_code.empty()) {
    try {
      character = source_code.at(character_index);
    } catch (std::exception &e) {
      current_character = '\0';
      return '\0';
    }
  } else {
    character = source_file->get();
  }

  if (character == EOF) {
    current_character = '\0';
    return '\0';
  } else {
    current_character = (char)character;
    return character;
  }
}

char Scanner::peek_char() {

  if (!source_code.empty()) {
    char character = source_code[character_index + 1];
    return character;
  }

  int current_index = source_file->tellg();
  char current_char = current_character;
  int current_index_backup = character_index;

  char character = consume_char();

  go_to(current_index);

  return character;
}

std::string Scanner::consume_word() {
  std::string word;
  char character = consume_char();

  while (!iswspace(character) && character != '\0' && character != '\n') {
    word += character;
    character = consume_char();
  }

  return word;
}

std::string Scanner::peek_word() {
  int current_index = source_file->tellg();
  std::string word = consume_word();

  source_file->seekg(current_index);

  return word;
}

int Scanner::get_index() { return character_index; }

bool Scanner::go_to(int i) {
  if (!source_code.empty()) {
    character_index = --i;
    consume_char();
    return true;
  }

  source_file->seekg(i);

  if (source_file->fail()) {
    source_file->seekg(get_index());

    return false;
  }

  character_index = --i;
  consume_char();

  return true;
}
