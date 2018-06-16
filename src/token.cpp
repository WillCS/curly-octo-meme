#include "token.h"

Token::Token(TokenType token, Location location) {
    this->token = token;
    this->location = location;
}

TokenType Token::getType() {
    return this->token;
}

Location Token::getLocation() {
    return this->location;
}