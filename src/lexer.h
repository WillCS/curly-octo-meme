#ifndef LEXER
#define LEXER

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <regex>

namespace curly_octo_meme {
    struct LexerEntry;
    class Lexer;
}

#include "language.h"
#include "location.h"
#include "token.h"

using std::string;
using std::list;
using std::ifstream;
using std::cout;   
using std::regex;
using std::streampos;

namespace curly_octo_meme {
    struct LexerEntry {
        public:
            LexerEntry(TokenType token, regex matcher);
            virtual TokenType getToken();
            virtual regex getRegex();
            virtual bool match(Lexer* lexer, string& match);
        private:
            TokenType token;
            regex matcher;
    };

    struct MultilineLexerEntry : public LexerEntry {
        public:
            MultilineLexerEntry(TokenType token, regex startMatcher, regex matcher);
            virtual bool match(Lexer* lexer, string& match);
        private:
            regex startMatcher;
    };

    class Lexer {
        public:
            virtual ~Lexer();
            virtual void openFile(string fileName);
            virtual void closeFile();
            virtual bool isOpen();
            virtual bool isEOF();
            virtual Location getLocation();
            virtual Token getToken();
            virtual void addToken(TokenType token, regex match);
            virtual void addToken(TokenType token, regex startMatch, regex match);
            virtual void readLine();
            virtual bool canReadLine();
            virtual string getCurrentLine();
            virtual void backupState();
            virtual void restoreState();
        private:
            virtual bool isEndOfLine();
            virtual void trimWhitespace();
            list<LexerEntry> entries;
            int line;
            int offset;
            ifstream file;
            string currentLine;
            int oldLine;
            int oldOffset;
            streampos oldPos;
            string oldCurrentLine;
    };
}

#endif