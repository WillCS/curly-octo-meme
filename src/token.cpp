#include "token.h"

using namespace curly_octo_meme;

Token::Token(TokenType token, Location* location) {
    this->location = location;
    this->token = token;
}

Token::Token(TokenType token, Location* location, string value) 
        :Token(token, location) {
    this->stringValue = value;
}

Token::Token(TokenType token, Location* location, float value) 
        :Token(token, location) {
    this->numValue = value;
}

string Token::getString() {
    return this->stringValue;
}

float Token::getNumber() {
    return this->numValue;
}

TokenType Token::getType() {
    return this->token;
}

Location* Token::getLocation() {
    return this->location;
}