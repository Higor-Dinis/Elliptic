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

#include <fstream>
#include <iostream>
#include <string>

#include "AST/parser.hpp"
#include "Generation/generator.hpp"
#include "lexer.hpp"

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    std::cout << "Error: No arguments given" << std::endl;
    return 1;
  }

  std::ifstream source_file;
  source_file.open(argv[1]);

  if (!source_file.is_open()) {
    std::cout << "Error: File not found" << std::endl;
    return 1;
  }

  auto lexer = Lexer();
  lexer.feed(&source_file);

  if (lexer.get_tokens().empty()) {
    std::cout << "Error: No tokens found" << std::endl;
    return 1;
  }

  auto parser = Parser(lexer.get_tokens());

  auto nodes = parser.parse();
  if (nodes.empty()) {
    std::cout << "Error: No nodes found" << std::endl;
    return 1;
  }

  AssemblyGenerator().generate(parser.parse());
  return 0;
}
