#ifndef LANGUAGE
#define LANGUAGE

#include <regex>
#include <string>
#include <cmath>

#include "lua/token_type.h"

namespace curly_octo_meme {
    typedef lua::LuaTokenType TokenType;
    const TokenType STRING_TOKEN_TYPE = TokenType::STRING;
    const TokenType NUMBER_TOKEN_TYPE = TokenType::NUMBER;
    const TokenType IDENTIFIER_TOKEN_TYPE = TokenType::IDENTIFIER;
}

#include "lexer.h"
#include "token.h"

namespace curly_octo_meme {
    Lexer* constructLexer();
    Token* getStringToken(std::string value, Location* loc);
    Token* getIdentifierToken(std::string value, Location* loc);
    Token* getNumberToken(std::string value, Location* loc);
}

#endif