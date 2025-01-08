#include "lexer.hpp"
#include "scanner.hpp"
#include <gtest/gtest.h>

TEST(LexerTest, PeekToken) {
  std::string input = "int variable = 245";
  Scanner scanner(input);
  Lexer lexer(&scanner);
  lexer.consume_token();

  Token token = lexer.peek_token();
  EXPECT_EQ(token.type, TokenType::IDENTIFIER);
  EXPECT_EQ(token.value, "variable");
}

TEST(LexerTest, GetTokens) {
  std::string input = "int variable = 245\nexit(variable)";
  Scanner scanner(input);
  Lexer lexer(&scanner);

  std::vector<Token> tokens = lexer.get_tokens();
  ASSERT_EQ(tokens.size(), 9);
  EXPECT_EQ(tokens[0].type, TokenType::IDENTIFIER);
  EXPECT_EQ(tokens[0].value, "int");
  EXPECT_EQ(tokens[1].type, TokenType::IDENTIFIER);
  EXPECT_EQ(tokens[1].value, "variable");
  EXPECT_EQ(tokens[2].type, TokenType::EQ);
  EXPECT_EQ(tokens[2].value, "=");
  EXPECT_EQ(tokens[3].type, TokenType::NUM);
  EXPECT_EQ(tokens[3].value, "245");
  EXPECT_EQ(tokens[4].type, TokenType::KEYWORD);
  EXPECT_EQ(tokens[4].value, "exit");
  EXPECT_EQ(tokens[5].type, TokenType::OPN_PAR);
  EXPECT_EQ(tokens[5].value, "(");
  EXPECT_EQ(tokens[6].type, TokenType::IDENTIFIER);
  EXPECT_EQ(tokens[6].value, "variable");
  EXPECT_EQ(tokens[7].type, TokenType::CLS_PAR);
  EXPECT_EQ(tokens[7].value, ")");
  EXPECT_EQ(tokens[8].type, TokenType::EOF_TOKEN);
  EXPECT_EQ(tokens[8].value, "");
}

TEST(LexerTest, ConsumeToken) {
  std::string input = "int";
  Scanner scanner(input);
  Lexer lexer(&scanner);

  Token token = lexer.consume_token();
  EXPECT_EQ(token.type, TokenType::IDENTIFIER);
  EXPECT_EQ(token.value, "int");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
