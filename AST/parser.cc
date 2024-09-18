#include "parser.h"

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
  actual_token = tokens.at(++token_index);
  return actual_token;
}

std::optional<NodeExit> Parser::parse() {
  while (peek(2).has_value()) {
    switch (actual_token.type) {
      case TokenType::EXIT:
        NodeExit node_exit;
        node_exit.expr = parse_expr();
        return node_exit;
    };
    consume();
  }
  return {};
}

NodeExpr Parser::parse_expr() {
  if (peek().has_value() && peek().value().type == TokenType::OPN_PAR) {
    consume();
    if (peek().has_value() && peek().value().type == TokenType::DEC_LIT) {
      consume();
      NodeExpr expression;
      expression.dec_lit = actual_token;

      return expression;
    }
  }
}