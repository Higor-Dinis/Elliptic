#include <string>

namespace Tokens {

enum TokenType {
  EXIT = 0
};

struct Token {
  TokenType type;
  std::vector<int> token_args;
};

}  // namespace Tokens