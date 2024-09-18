#pragma once
#include <optional>
#include <vector>

#include "../tokens.h"
#include "nodes.h"

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

  std::optional<NodeExit> parse();

  NodeExpr parse_expr();
};
