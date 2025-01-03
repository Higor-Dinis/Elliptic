#pragma once

#include <fstream>
#include <optional>

class Scanner {
 private:
  std::ifstream* file;
  int char_index;
  char actual_char;

 public:
  /**
   * The scanner constructor.
   *
   * Args:
   *  (std::ifstream*) file: A file stream pointer, where the code will be
   * extracted.
   *
   * Raises:
   *  (std::runtime_error) When it cannot open the file.
   */
  explicit Scanner(std::ifstream file);

  /**
   * The scanner constructor.
   *
   * Args:
   *  (std::string) file_path: A string containing a path to the source file.
   *
   * Raises:
   *  (std::runtime_error) When it cannot open the file.
   */
  explicit Scanner(std::string file_path);
  ~Scanner();

  /**
   * Peeks the next character in the source code.
   *
   * Return:
   *  std::optional<char>: The character (or not).
   */
  std::optional<char> peek();

  /**
   * Peeks ahead the given number of characters.
   *
   * Args:
   *  (int) i: The number of characters to peek ahead.
   *
   * Return:
   *  std::optional<char>: The character (or not).
   * 
   * TODO: Implement this.
   */
  std::optional<char> peek(int i);

  /**
   * Consumes the actual character.
   * 
   * Return:
   *  char: The actual character.
   */
  char consume();
};
