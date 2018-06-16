#include "token.h"

using namespace curly_octo_meme;

Token::Token(TokenType token, Location location) 
    :location(location) {
    this->token = token;
}

TokenType Token::getType() {
    return this->token;
}

Location Token::getLocation() {
    return this->location;
}