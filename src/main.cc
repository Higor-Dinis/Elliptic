#include <iostream>
#include <string>
#include <fstream>
#include "lexer.hpp"
#include "./AST/parser.hpp"
#include "./Generation/generator.hpp"

int main(int argc, char const *argv[])
{
  if (argc < 2) {
    std::cout << "Error: No arguments given" << std::endl;
    return 1;
  }

  std::ifstream source_file;
  source_file.open(argv[1]);

  if (source_file.fail()) {
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
