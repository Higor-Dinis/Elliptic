#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include "../tokens.hpp"

enum class NodeType {
    EXIT,
    EXPR
};

struct NodeExpr {
    Token dec_lit;
};

struct NodeExit {
    NodeExpr expr;
};

struct Node {
    NodeType type;
    std::variant<NodeExpr, NodeExit> value;
};
