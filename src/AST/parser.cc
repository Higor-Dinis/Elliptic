#include "AST/parser.hpp"

#include <iostream>

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

  while (peek(2).has_value()) {
    switch (actual_token.type) {
      case TokenType::KEYWORD: {
        if (actual_token.value == "exit") {
          NodeExit node_exit;
          node_exit.expr = parse_expr();

          Node node;
          node.type = NodeType::EXIT;
          node.value = node_exit;

          nodes.push_back(node);

          return nodes;
        }
      };
        consume();
    }
    return {};
  }
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