#pragma once
#include <string>

enum class TokenType { EXIT = 0, OPN_PAR, CLS_PAR, DEC_LIT };

/**
 * The Token struct.
 *
 * Properties:
 *  (TokenType) type: The token type.
 *  (std::string) value: The token value.
 */
struct Token {
  TokenType type; // (TokenType) type: The token type.
  std::string value; // (std::string) value: The token value.
};