#ifndef TOKEN
#define TOKEN

#include "language.h"
#include "location.h"

namespace curly_octo_meme {
    struct Token {
        public:
            Token(TokenType type, Location location);
            virtual TokenType getType();
            virtual Location getLocation();
        private:
            TokenType token;
            Location location;
    };
}
#endif