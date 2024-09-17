#include <string>

namespace Tokens {

enum TokenType {
  EXIT = 0, OPN_PAR, CLS_PAR, DEC_LIT
};

struct Token {
  TokenType type;
  std::string value;
};

}  // namespace Tokens