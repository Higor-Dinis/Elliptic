// Copyright [2025] <Higor Dinis>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include <vector>
#include <optional>

#include "scanner.hpp"
#include "tokens.hpp"

class Lexer {
  public:
    Lexer(Scanner* scanner);

    Token peek_token();
    Token consume_token();
    // Token get_at(int i);

    std::vector<Token> get_tokens();

    bool is_token(TokenType type);
    bool is_token(TokenType type, std::string value);
  private:
    Scanner* scanner;

    std::string buffer;
    int token_index;
    
    bool lexing_identifier;
    bool lexing_num_lit;
    bool lexing_str_lit;

    Token process_token();

    void handle_whitespace();
    void handle_new_line();
    std::optional<Token> handle_number();
    std::optional<Token> handle_identifier();

    std::optional<Token> handle_nonalpha_char();

    bool can_be_identifier(std::string identifier);
    bool can_be_identifier(char c);

    bool can_be_numeric(std::string numeric);

    bool is_keyword(std::string keyword);
};
