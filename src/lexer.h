#ifndef LEXER
#define LEXER

#include <string>
#include <list>
#include <fstream>
#include <iostream>

#include "language.h"

using std::string;
using std::list;
using std::ifstream;

namespace curly_octo_meme {
    struct LexerEntry {
        public:
            LexerEntry(TokenType token, string regex);
            virtual TokenType getToken();
            virtual string getRegex();
        private:
            TokenType token;
            string regex;
    };

    class Lexer {
        public:
            Lexer();
            ~Lexer();
            virtual void openFile(string fileName);
            virtual void closeFile();
            virtual int getLocation();
            virtual TokenType getToken();
            virtual void addToken(TokenType token, string regex);
        private:
            list<LexerEntry*> *entries;
            int line;
            int offset;
            bool open;
            ifstream* file;
    };
}

#endif