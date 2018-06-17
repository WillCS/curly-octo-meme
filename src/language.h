#ifndef LANGUAGE
#define LANGUAGE

#include <regex>

#include "lua/token_type.h"

namespace curly_octo_meme {
    typedef lua::LuaTokenType TokenType;
    const TokenType stringTokenType = TokenType::STRING;
    const TokenType numberTokenType = TokenType::NUMBER;
    const TokenType identifierTokenType = TokenType::IDENTIFIER;
}

#include "lexer.h"

namespace curly_octo_meme {
    Lexer* constructLexer();
}

#endif