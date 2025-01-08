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

Lexer::Lexer(Scanner* scanner) : scanner(scanner), token_index(-1) {
  scanner->consume_char();
}

Token Lexer::peek_token() {
  int current_index = scanner->get_index();

  auto token = process_token();

  scanner->go_to(current_index);
  return token;
}

std::vector<Token> Lexer::get_tokens() {
  std::vector<Token> tokens;
  Token current_token;

  while (current_token.type != TokenType::EOF_TOKEN) {
    current_token = consume_token();
    tokens.push_back(current_token);
  }

  return tokens;
}

Token Lexer::consume_token() { return process_token(); }

Token Lexer::process_token() {
  while (scanner->get_current_char() != '\0') {
    buffer.clear();

    if (iswspace(scanner->get_current_char())) {
      handle_whitespace();
      continue;
    } else if (scanner->get_current_char() == '\n') {
      handle_new_line();
      continue;
    } else if (scanner->get_current_char() == '\0') {
      Token eof_token;

      eof_token.type = TokenType::EOF_TOKEN;
      eof_token.value = "\0";

      return eof_token;
    } else {
      auto token = handle_nonalpha_char();
      if (token.has_value()) {
        scanner->consume_char();

        return token.value();
      }
    }

    if (isalnum(scanner->get_current_char()) ||
        scanner->get_current_char() == '_') {
      while (isalnum(scanner->get_current_char()) ||
             scanner->get_current_char() == '_') {
        buffer += scanner->get_current_char();
        scanner->consume_char();
      }

      Token token;

      if (is_keyword(buffer)) {
        token.type = TokenType::KEYWORD;
        token.value = buffer;
      } else if (can_be_identifier(buffer)) {
        token.type = TokenType::IDENTIFIER;
        token.value = buffer;
      } else if (can_be_numeric(buffer)) {
        token.type = TokenType::NUM;
        token.value = buffer;
      } else {
        token.type = TokenType::UNKNOWN;
        token.value = "";
      }

      return token;
    }

    scanner->consume_char();
  }

  Token eof_token;

  eof_token.type = TokenType::EOF_TOKEN;
  eof_token.value = "\0";

  return eof_token;
}

void Lexer::handle_whitespace() {
  while (iswspace(scanner->get_current_char())) {
    scanner->consume_char();
  }
}

void Lexer::handle_new_line() {
  while (scanner->get_current_char() == '\n') {
    scanner->consume_char();
  }
}

std::optional<Token> Lexer::handle_number() {
  buffer.clear();

  while (isdigit(scanner->get_current_char())) {
    buffer += scanner->get_current_char();

    scanner->consume_char();
  }

  Token num_token;
  num_token.type = TokenType::NUM;
  num_token.value = buffer;

  return num_token;
}

bool Lexer::can_be_identifier(std::string identifier) {
  if (isalpha(identifier[0]) || identifier[0] == '_') {
    for (auto character : identifier) {
      if (!isalnum(character) && character != '_') {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Lexer::can_be_identifier(char c) { return isalpha(c) || c == '_'; }

bool Lexer::can_be_numeric(std::string numeric) {
  if (isdigit(numeric[0]) || numeric[0] == '.') {
    for (auto character : numeric) {
      if (!isdigit(character) && character != '.') {
        return false;
      }
    }
    return true;
  }
  return false;
}

std::optional<Token> Lexer::handle_nonalpha_char() {
  char current_char = scanner->get_current_char();

  auto create_token = [&](TokenType type, const std::string& value) {
    Token token;
    token.type = type;
    token.value = value;
    return token;
  };

  switch (current_char) {
    case '(':
      return create_token(TokenType::OPN_PAR, "(");
    case ')':
      return create_token(TokenType::CLS_PAR, ")");
    case '[':
      return create_token(TokenType::OPN_BRACKET, "[");
    case ']':
      return create_token(TokenType::CLS_BRACKET, "]");
    case '=':
      return create_token(TokenType::EQ, "=");
    case '+':
      return create_token(TokenType::PLUS, "+");
    case '-':
      return create_token(TokenType::MINUS, "-");
    case '*':
      return create_token(TokenType::STAR, "*");
    case '%':
      return create_token(TokenType::PERCENT, "%");
    case '/':
      return create_token(TokenType::R_BAR, "/");
    case '\\':
      return create_token(TokenType::L_BAR, "\\");
    case '|':
      return create_token(TokenType::PIPE, "|");
    case '&':
      return create_token(TokenType::AND, "&");
    case '!':
      return create_token(TokenType::EXCLAMATION, "!");
    case '@':
      return create_token(TokenType::AT, "@");
    case '\0':
      return create_token(TokenType::EOF_TOKEN, "EOF");
    default:
      return std::nullopt;
  }
}

bool Lexer::is_keyword(std::string keyword) {
  for (auto keyword_str : keywords) {
    if (keyword_str == keyword) {
      return true;
    }
  }

  return false;
}
