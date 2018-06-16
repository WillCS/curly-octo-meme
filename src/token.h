#ifndef TOKEN
#define TOKEN

#include "lua/token_type.h"
#include "location.h"

struct Token {
    public:
        Token(TokenType type, Location location);
        virtual TokenType getType();
        virtual Location getLocation();
    private:
        TokenType token;
        Location location;
};
#endif