#ifndef TOKEN
#define TOKEN

#include <string>

namespace curly_octo_meme {
    struct Token;
}

#include "language.h"
#include "location.h"

using std::string;

namespace curly_octo_meme {
    struct Token {
        public:
            Token(TokenType type, Location location);
            Token(TokenType type, Location location, string value);
            Token(TokenType type, Location location, float value);
            virtual TokenType getType();
            virtual Location getLocation();
            virtual string getString();
            virtual float getNumber();
        private:
            TokenType token;
            Location location;
            float numValue;
            string stringValue;
    };
}
#endif