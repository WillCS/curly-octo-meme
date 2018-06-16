#include "lexer.h"

LexerEntry::LexerEntry(TokenType token, string regex) {
    this->token = token;
    this->regex = regex;
}

TokenType LexerEntry::getToken() {
    return this->token;
}

string LexerEntry::getRegex() {
    return this->regex;
}

Lexer::Lexer() {
    this->entries = new list<LexerEntry*>();
}

Lexer::~Lexer() {
    for(auto const &entry : *(this->entries)) {
        delete entry;
    }

    delete this->entries;
}

void Lexer::addToken(TokenType token, string regex) {
    LexerEntry* entry = new LexerEntry(token, regex);
    this->entries->push_back(entry);
}
