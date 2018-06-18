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
        
    lexer->addToken(TokenType::MODULUS, 
        std::regex("^%%"));
        
    lexer->addToken(TokenType::MULTIPLY, 
        std::regex("^\\*"));
        
    lexer->addToken(TokenType::DIVIDE, 
        std::regex("^/"));

    lexer->addToken(TokenType::COMMA, 
        std::regex("^,"));

    lexer->addToken(TokenType::VARARG, 
        std::regex("^\\.{3}"));

    lexer->addToken(TokenType::CONCAT, 
        std::regex("^\\.{2}"));

    lexer->addToken(TokenType::EXPONENT, 
        std::regex("^\\^"));
        
    lexer->addToken(TokenType::SEMICOLON, 
        std::regex("^;"));
        
    lexer->addToken(TokenType::COLON, 
        std::regex("^:"));
        
    lexer->addToken(TokenType::LESSEQ, 
        std::regex("^<="));
        
    lexer->addToken(TokenType::LESS, 
        std::regex("^<"));
        
    lexer->addToken(TokenType::GREATEREQ, 
        std::regex("^>="));
        
    lexer->addToken(TokenType::GREATER, 
        std::regex("^>"));
        
    lexer->addToken(TokenType::EQUALS, 
        std::regex("^=="));
        
    lexer->addToken(TokenType::NEQUALS, 
        std::regex("^~="));
        
    lexer->addToken(TokenType::ASSIGN, 
        std::regex("^="));
        
    lexer->addToken(TokenType::LENGTH, 
        std::regex("^#"));

    lexer->addToken(TokenType::COMMENT, std::regex("^--\\[(=*)\\["),
        std::regex("^--\\[(=*)\\[(?:(?!(\\[\\1\\[)|(\\]\\1\\]))(.|\\n|\\r|\\f))*\\]\\1\\]"));
        
    lexer->addToken(TokenType::COMMENT,
        std::regex("^--.*"));

    lexer->addToken(TokenType::MINUS, 
        std::regex("^-"));
        
    lexer->addToken(TokenType::STRING, std::regex("^\\[(=*)\\["),
        std::regex("^\\[(=*)\\[(?:(?!(\\[\\1\\[)|(\\]\\1\\]))(.|\\n|\\r|\\f))*\\]\\1\\]"));

    lexer->addToken(TokenType::LBRACKET, 
        std::regex("^\\["));

    lexer->addToken(TokenType::RBRACKET, 
        std::regex("^\\]"));

    lexer->addToken(TokenType::STRING, 
        std::regex("^(\"|')(?:(?!\\1)((\\\\\\1)|.))*\\1"));

    lexer->addToken(TokenType::NUMBER, 
        std::regex("^((\\d+(\\.\\d+))|(\\d+\\.?)|(\\.\\d+))((e|E)(\\+?|-)\\d+)?\\b"));

    lexer->addToken(TokenType::DOT, 
        std::regex("^\\."));

    lexer->addToken(TokenType::IDENTIFIER, 
        std::regex("^(([a-z]|[A-Z]|_)\\w*)\\b"));

    lexer->addToken(TokenType::INVALID,
        std::regex("^[^\\s]\\w*"));

    return lexer;
}

/** Regular expression for matching leading whitespace in a multiline
 *  string.
 *  Raw expression: (\r\n|\r|\n)( |\t)*
 */
const std::regex whitespaceMatcher = std::regex("(\\r\\n|\\r|\\n)( |\\t)*");

/** Regular expression for matching a newline at the start of a multiline
 *  string. 
 *  Raw exprssion: ^(\r\n|\r|\n)
 */
const std::regex emptyFirstLineMatcher = std::regex("^(\\r\\n|\\r|\\n)");

/** Multiline strings should not retain leading whitespace, so we get
 *  rid of it here. 
 */
std::string fixString(std::string value) {
    value = std::regex_replace(value, whitespaceMatcher, "\n");
    return std::regex_replace(value, emptyFirstLineMatcher, "");
}

Token curly_octo_meme::getStringToken(std::string value, Location loc) {
    int snipSize = 1;
    bool multiline = false;
    if(value[0] == '[') {
        multiline = true;
        snipSize = value.find('[', 1) + 1;
    }
    value = value.substr(snipSize, value.length() - (2 * snipSize));
    if(multiline) {
        value = fixString(value);
    }
    
    return Token(STRING_TOKEN_TYPE, loc, value);
}

Token curly_octo_meme::getIdentifierToken(std::string value, Location loc) {
    return Token(IDENTIFIER_TOKEN_TYPE, loc, value);
}

/** Regular expression for matching the significand of a number in e
 *  notation. 
 *  Raw expression: .*(?=(E|e))
 */
const std::regex significandMatcher = std::regex(".*(?=(E|e))");

/** Regular expression for matching the exponent of a number in e notation. 
 *  Raw expression: (\+|-)?\d+$
 */
const std::regex exponentMatcher = std::regex("(\\+|-)?\\d+$");

/** Lua accepts some deformed ass numbers as valid so we fix them here
 *  just to be safe before doing anything else with them.
 *  Examples:   .7 -> 0.7
 *              32. -> 32 
 */
std::string fixFloat(std::string value) {
    if(value[0] == '.') {
        value = std::string("0").append(value);
    } else if(value[value.length() - 1] == '.') {
        value = value.substr(0, value.length() - 1);
    }

    return value;
}

Token curly_octo_meme::getNumberToken(std::string value, Location loc) {
    float number;

    if(value.find('e') == string::npos && value.find("E") == string::npos) {
        number = std::stof(fixFloat(value));
    } else {
        std::smatch sigMatch;
        std::regex_search(value, sigMatch, significandMatcher);
        float significand = std::stof(fixFloat(sigMatch[0]));
        
        std::smatch expMatch;
        std::regex_search(value, expMatch, exponentMatcher);
        int exponent = std::stoi(expMatch[0]);

        number = significand * std::pow(10, exponent);
    }

    return Token(NUMBER_TOKEN_TYPE, loc, number);
}