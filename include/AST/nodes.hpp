/**
 * @file nodes.hpp
 * @brief Defines the structures representing nodes in the abstract syntax tree (AST) for the Eliptic project.
 * 
 * This file contains the definitions of various node types that can appear in the AST, including expression nodes
 * and exit nodes. Each node type is represented by a specific structure, and the Node struct encapsulates these
 * different types using a variant.
 * 
 * @copyright [2025] <Higor Dinis>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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


#pragma once

#include <iostream>
#include <vector>
#include <variant>

#include "../tokens.hpp"

/**
 * @enum NodeType
 * @brief Enumerates the types of nodes that can appear in the AST.
 * 
 * This enumeration defines the different types of nodes that can be
 * represented in the abstract syntax tree (AST).
 * 
 * @var NodeType::EXIT
 * Represents an exit node in the AST.
 * 
 * @var NodeType::EXPR
 * Represents an expression node in the AST.
 */
enum class NodeType {
    EXIT,
    EXPR
};

/**
 * @struct NodeExpr
 * @brief Represents an expression node in the abstract syntax tree (AST).
 * 
 * This structure is used to store information about a specific type of 
 * expression node within the AST. It currently holds a single member 
 * representing a decimal literal token.
 * 
 * @var NodeExpr::dec_lit
 * Token representing a decimal literal.
 */
struct NodeExpr {
    Token dec_lit;
};

/**
 * @struct NodeExit
 * @brief Represents an exit node in the AST (Abstract Syntax Tree).
 * 
 * The NodeExit struct contains an expression node, which is used to represent
 * the expression associated with the exit statement in the AST.
 * 
 * @var NodeExit::expr
 * The expression node associated with the exit statement.
 */
struct NodeExit {
    NodeExpr expr;
};

/**
 * @struct Node
 * @brief Represents a node in the AST (Abstract Syntax Tree).
 * 
 * The Node struct is used to encapsulate different types of nodes
 * that can appear in the AST. Each node has a type and a value.
 * 
 * @var Node::type
 * The type of the node, represented by the NodeType enum.
 * 
 * @var Node::value
 * The value of the node, which can be either a NodeExpr or a NodeExit,
 * encapsulated in a std::variant.
 */
struct Node {
    NodeType type;
    std::variant<NodeExpr, NodeExit> value;
};
