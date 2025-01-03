#pragma once
#include <optional>
#include <vector>

#include "../tokens.hpp"
#include "nodes.hpp"

class Parser {
 private:
  int token_index = -1;
  Token actual_token;

  std::vector<Token> tokens;

  std::optional<Token> peek();

  std::optional<Token> peek(int i);

  Token consume();

 public:
  Parser(std::vector<Token> tokens);
  ~Parser();

  std::vector<Node> parse();

  NodeExpr parse_expr();
};
