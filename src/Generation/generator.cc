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
}
