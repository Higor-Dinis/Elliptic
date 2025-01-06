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

#include "AST/parser.hpp"

#include <iostream>
#include <vector>

Parser::Parser(std::vector<Token> tokens) {
  this->tokens = tokens;
  actual_token = consume();
}

Parser::~Parser() { tokens.clear(); }

std::optional<Token> Parser::peek() {
  if ((token_index + 1) < tokens.size()) {
    return tokens.at(token_index + 1);
  }
  return {};
}

std::optional<Token> Parser::peek(int i) {
  if ((token_index + i) < tokens.size()) {
    return tokens.at(token_index + i);
  }
  return {};
}

Token Parser::consume() {
  if (token_index + 1 < tokens.size()) {
    actual_token = tokens.at(++token_index);
    return actual_token;
  }
  return {};
}

std::vector<Node> Parser::parse() {
  std::vector<Node> nodes;

  while (actual_token.type != TokenType::EOF_TOKEN) {
    switch (actual_token.type) {
      case TokenType::KEYWORD: {
        if (actual_token.value == "exit") {
          NodeExit node_exit;
          node_exit.expr = parse_expr();

          nodes.push_back(node_exit);

          return nodes;
        }
      } break;
      case TokenType::EQ: {
        if (peek(-1).has_value() && peek(-1).value().type == TokenType::IDENTIFIER && peek(-2).has_value() && peek(-2).value().type == TokenType::IDENTIFIER) {
          NodeVarDeclaration node_var_decl;
          node_var_decl.identifier = peek(-1).value();
          node_var_decl.type_id = peek(-2).value();

          if (peek().has_value() && peek().value().type == TokenType::DEC_LIT) {
            node_var_decl.expr = parse_expr();
          }
        }
      } break;
    }

    consume();
  }

  return {};
}

NodeExpr Parser::parse_expr() {
  NodeExpr expr;

  if (peek().has_value() && peek().value().type == TokenType::OPN_PAR) {
    consume();
    expr = parse_expr();

    if (peek().has_value() && peek().value().type == TokenType::CLS_PAR) {
      consume();
    } else {
      std::cerr << "Syntax error: expected ')'" << std::endl;
    }
    return expr;
  }

  if (peek().has_value() && peek().value().type == TokenType::DEC_LIT) {
    expr.dec_lit = consume();
    return expr;
  }

  return {};
}
