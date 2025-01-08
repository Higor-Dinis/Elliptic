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

#pragma once

#include <optional>
#include <vector>

#include "AST/nodes.hpp"
#include "lexer.hpp"
#include "tokens.hpp"

enum class Types {
  INT, FLOAT, STR
};

class Parser {
 public:
  Parser(std::vector<Token> tokens);

  Node consume_node();

  std::vector<Node> get_nodes();

 private:
  std::vector<Token> tokens;

  int token_index;
  Token current_token;

  Token peek_token();
  Token consume_token();

  Node process_node();

  NodeExpr parse_expr();
  NodeExit parse_exit();
  NodeVarDeclaration parse_var_decl();
  NodeVarAssignment parse_var_assgn();

  std::vector<Node> get_tokens_in_par();
  std::vector<Node> get_tokens_in_bracket();
};