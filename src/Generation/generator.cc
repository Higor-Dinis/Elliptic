#include <iostream>
#include <vector>

#include "Generation/generator.hpp"
#include "AST/nodes.hpp"

void AssemblyGenerator::generate(std::vector<Node> nodes) {
  std::cout << "section .text" << std::endl;
  std::cout << "global _start" << std::endl;
  std::cout << "_start:" << std::endl;

  for (auto& node : nodes) {
    switch (node.type) {
      case NodeType::EXIT: {
        const NodeExit& nodeExit = std::get<NodeExit>(node.value);
        std::cout << "  mov rax, 60" << std::endl;
        std::cout << "  mov rdi, " << nodeExit.expr.dec_lit.value << std::endl;
        std::cout << "  syscall" << std::endl;
        std::cout << "  ret" << std::endl;
        break;
      }
      case NodeType::EXPR: {
        const NodeExpr& nodeExpr = std::get<NodeExpr>(node.value);
        std::cout << "  mov eax, " << nodeExpr.dec_lit.value << std::endl;
        break;
      }
    }
  }
};