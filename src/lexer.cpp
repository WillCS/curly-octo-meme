#include "lexer.h"

using namespace curly_octo_meme;

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
    this->file = new ifstream();
    this->entries = new list<LexerEntry*>();
    this->open = false;
}

Lexer::~Lexer() {
    delete this->entries;
    delete this->file;
}

void Lexer::openFile(string fileName) {
    if(this->open) {
        this->closeFile();
    }

    this->file->open(fileName);
    this->open = true;
    this->line = 0;
    this->offset = 0;
}

void Lexer::closeFile() {
    this->file->close();
    this->open = false;
}

void Lexer::addToken(TokenType token, string regex) {
    LexerEntry* entry = new LexerEntry(token, regex);
    this->entries->push_back(entry);
}
