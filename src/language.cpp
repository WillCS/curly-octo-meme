#include "language.h"

using namespace curly_octo_meme;

Lexer* curly_octo_meme::constructLexer() {
    Lexer* lexer = new Lexer();

    lexer->addToken(TokenType::KW_DO,
        std::regex("^(do)\\b"));

    lexer->addToken(TokenType::KW_WHILE,
        std::regex("^(while)\\b"));

    lexer->addToken(TokenType::KW_REPEAT,
        std::regex("^(repeat)\\b"));

    lexer->addToken(TokenType::KW_UNTIL,
        std::regex("^(until)\\b"));

    lexer->addToken(TokenType::KW_IF,
        std::regex("^(if)\\b"));

    lexer->addToken(TokenType::KW_THEN,
        std::regex("^(then)\\b"));

    lexer->addToken(TokenType::KW_ELSEIF,
        std::regex("^(elseif)\\b"));

    lexer->addToken(TokenType::KW_ELSE,
        std::regex("^(else)\\b"));

    lexer->addToken(TokenType::KW_FOR,
        std::regex("^(for)\\b"));

    lexer->addToken(TokenType::KW_FUNCTION, 
        std::regex("^(function)\\b"));
        
    lexer->addToken(TokenType::KW_RETURN, 
        std::regex("^(return)\\b"));

    lexer->addToken(TokenType::KW_BREAK, 
        std::regex("^(break)\\b"));

    lexer->addToken(TokenType::KW_LOCAL, 
        std::regex("^(local)\\b"));

    lexer->addToken(TokenType::KW_NIL, 
        std::regex("^(nil)\\b"));

    lexer->addToken(TokenType::KW_FALSE, 
        std::regex("^(false)\\b"));

    lexer->addToken(TokenType::KW_TRUE, 
        std::regex("^(true)\\b"));

    lexer->addToken(TokenType::KW_AND, 
        std::regex("^(and)\\b"));

    lexer->addToken(TokenType::KW_OR, 
        std::regex("^(or)\\b"));

    lexer->addToken(TokenType::KW_NOT, 
        std::regex("^(not)\\b"));

    lexer->addToken(TokenType::KW_END, 
        std::regex("^(end)\\b"));

    lexer->addToken(TokenType::LPAREN, 
        std::regex("^\\("));

    lexer->addToken(TokenType::RPAREN, 
        std::regex("^\\)"));

    lexer->addToken(TokenType::LBRACE, 
        std::regex("^\\{"));

    lexer->addToken(TokenType::RBRACE, 
        std::regex("^\\}"));
        
    lexer->addToken(TokenType::PLUS, 
        std::regex("^\\+"));
        
    lexer->addToken(TokenType::MINUS, 
        std::regex("^-"));
        
    lexer->addToken(TokenType::ASSIGN, 
        std::regex("^="));

    lexer->addToken(TokenType::COMMA, 
        std::regex("^,"));

    lexer->addToken(TokenType::DOT, 
        std::regex("^\\."));
        
    lexer->addToken(TokenType::STRING, std::regex("^\\[(=*)\\["),
        std::regex("^\\[(=*)\\[(?:(?!(\\[\\1\\[)|(\\]\\1\\]))(.|\\n|\\r|\\f))*\\]\\1\\]"));

    lexer->addToken(TokenType::LBRACKET, 
        std::regex("^\\["));

    lexer->addToken(TokenType::RBRACKET, 
        std::regex("^\\]"));

    lexer->addToken(TokenType::STRING, 
        std::regex("^(\"|\')((\\\")|(\\\')|[^\"\'])*\\1"));

    lexer->addToken(TokenType::NUMBER, 
        std::regex("^((\\d+(\\.\\d+))|(\\d+\\.?)|(\\.\\d+))((e|E)(\\+?|-)\\d+)?\\b"));

    lexer->addToken(TokenType::IDENTIFIER, 
        std::regex("^(([a-z]|[A-Z]|_)\\w*)\\b"));

    lexer->addToken(TokenType::INVALID,
        std::regex("^[^\\s]\\w*"));

    return lexer;
}