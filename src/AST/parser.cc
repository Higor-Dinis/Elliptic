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

#include <optional>
#include <vector>

#include "AST/nodes.hpp"
#include "tokens.hpp"

Parser::Parser(std::vector<Token> tokens) {
  this->tokens = tokens;
  this->token_index = -1;
  this->current_token = consume_token();
};

Token Parser::peek_token() { return tokens.at(token_index + 1); }
Token Parser::consume_token() {
  current_token = tokens.at(++token_index);
  return current_token;
}

Node Parser::consume_node() {}

std::vector<Node> Parser::get_nodes() {
  std::vector<Node> nodes;

  while (peek_token().type != TokenType::EOF_TOKEN) {
    nodes.push_back(process_node());
  }
  return nodes;
}

NodeExpr Parser::parse_expr() {
  if (peek_token().type == TokenType::NUM) {
    auto int_lit = consume_token();

    NodeExpr expr;
    expr.dec_lit = int_lit;  // Atribuindo o valor do literal
    return expr;
  } else if (peek_token().type == TokenType::IDENTIFIER) {
    NodeExpr expr;
    expr.dec_lit = consume_token();

    return expr;
  }

  // Adicionar mais verificações para diferentes tipos de expressões, se
  // necessário Exemplo: Expressões binárias, chamadas de função, etc.

  return NodeExpr();  // Retorna uma expressão vazia se não for um número
}

Node Parser::process_node() {
  std::vector<Token> buffer;

  while (peek_token().type != TokenType::EOF_TOKEN) {
    if (current_token.type == TokenType::EQ) {
      // Se o token de '=' for encontrado, verificamos a declaração de variável
      if (buffer.size() == 2 && buffer[0].type == TokenType::IDENTIFIER &&
          buffer[1].type == TokenType::IDENTIFIER) {
        NodeVarDeclaration var_decl;
        var_decl.type_id = buffer[0];  // O primeiro identificador é o tipo
        var_decl.identifier =
            buffer[1];  // O segundo identificador é o nome da variável

        var_decl.expr =
            parse_expr();  // A expressão à direita do '=' é analisada

        return var_decl;  // Retorna a declaração de variável
      }
    } else if (current_token.type == TokenType::KEYWORD) {
      // Verificando se é uma palavra-chave, como "exit"
      if (current_token.value == "exit") {
        // A palavra-chave "exit" pode ter uma expressão associada
        NodeExit exit;

        // Espera-se que após "exit" exista um parêntese de abertura
        if (peek_token().type == TokenType::OPN_PAR) {
          consume_token();           // Consome o parêntese de abertura
          exit.expr = parse_expr();  // Processa a expressão dentro do parêntese

          // Verifica se existe um parêntese de fechamento
          if (peek_token().type == TokenType::CLS_PAR) {
            consume_token();  // Consome o parêntese de fechamento
            return exit;      // Retorna o nó de saída
          } else {
            // Caso o parêntese de fechamento não seja encontrado
            throw std::runtime_error(
                "Expected closing parenthesis for 'exit' expression.");
          }
        } else {
          // Caso não encontre o parêntese de abertura
          throw std::runtime_error(
              "Expected opening parenthesis after 'exit'.");
        }
      }
    } else {
      // Acumula tokens para processar depois
      buffer.push_back(current_token);
      consume_token();
    }
  }

  // Retorna um nó vazio se nenhum tipo de expressão ou declaração for
  // encontrado
  return Node();
}