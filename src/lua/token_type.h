#ifndef TOKEN_TYPE
#define TOKEN_TYPE

namespace curly_octo_meme {
    namespace lua {
        enum class LuaTokenType {
            KW_DO,
            KW_END,
            KW_WHILE,
            KW_REPEAT,
            KW_UNTIL,
            KW_IF,
            KW_THEN,
            KW_ELSEIF,
            KW_ELSE,
            KW_FOR,
            KW_ASSIGN,
            KW_COMMA,
            KW_IN,
            KW_FUNCTION,
            KW_LOCAL,
            KW_RETURN,
            KW_BREAK,
            KW_DOT,
            KW_COLON,
            KW_LBRACKET,
            KW_RBRACKET,
            KW_NIL,
            KW_FALSE,
            KW_TRUE,
            VARARG,
            LPAREN,
            RPAREN,
            LBRACE,
            RBRACE,
            SEMICOLON,
            PLUS,
            MINUS,
            MULTIPLY,
            DIVIDE,
            EXPONENT,
            MODULUS,
            CONCAT,
            LESS,
            LESSEQ,
            GREATER,
            GREATEREQ,
            EQUALS,
            NEQUALS,
            AND,
            OR,
            NOT,
            LENGTH
        };
    }
}

#endif