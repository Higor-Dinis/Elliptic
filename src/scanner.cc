#include "scanner.hpp"

Scanner::Scanner(std::ifstream file) {
  if (file.is_open()) {
    this->file = &file;
  } else {
    throw std::runtime_error("File isn't open.");
  }
}

Scanner::Scanner(std::string file_path) {
  file->open(file_path);
  if (file->fail()) {
    throw std::runtime_error("Error when opening file.");
  }
}

std::optional<char> Scanner::peek() {
  actual_char = (char)file->peek();
  if ((int)actual_char != EOF) {
    return actual_char;
  } else {
    return {};
  }
}

// std::optional<char> Scanner::peek(int i) {
//   actual_char = file.get();
//   if ((int)actual_char != EOF) {
//     return actual_char;
//   } else {
//     return {};
//   }
// }

Scanner::~Scanner() { this->file->close(); }
