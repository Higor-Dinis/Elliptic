#include <iostream>
#include <string>
#include <fstream>
#include "lexer.h"

int main(int argc, char const *argv[])
{
  if (argc < 1) {
    std::cout << "Error: No arguments given" << std::endl;
    return 1;
  }

  std::ifstream source_file;
  source_file.open(argv[1]);
  auto lexer = Lexer();
  lexer.feed(&source_file);

  return 0;
}
