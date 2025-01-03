#pragma once

#include <iostream>
#include "../AST/nodes.hpp"
#include <vector>

class AssemblyGenerator {
 public:
  void generate(std::vector<Node> nodes);
};