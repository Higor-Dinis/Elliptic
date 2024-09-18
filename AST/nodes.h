#pragma once
#include "../tokens.h"

struct NodeExpr
{
  Token dec_lit;
};

struct NodeExit 
{
  NodeExpr expr;
};