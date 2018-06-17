#ifndef TOKEN_TYPE
#define TOKEN_TYPE

namespace curly_octo_meme {
    namespace lua {
        enum LuaTokenType {
            STRING,
            NUMBER,
            IDENTIFIER,
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
            ASSIGN,
            COMMA,
            KW_IN,
            KW_FUNCTION,
            KW_LOCAL,
            KW_RETURN,
            KW_BREAK,
            DOT,
            COLON,
            LBRACKET,
            RBRACKET,
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
            KW_AND,
            KW_OR,
            KW_NOT,
            LENGTH,
            END_OF_FILE,
            INVALID
        };
    }
}

#endif