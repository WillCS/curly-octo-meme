#ifndef LEXER
#define LEXER

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <regex>

namespace curly_octo_meme {
    /** Structure containing a terminal token type and a regular expression
     *  matching all strings of that terminal type. */
    struct LexerEntry;
    /** Structure containing a terminal token type, a regular expression
     *  matching the beginning of a multiline string of that terminal type,
     *  and a regular expression matching all strings of that terminal type. */
    struct MultilineLexerEntry;
    /** Lexical Analyser class. Constructed from Lexer Entries. Analyses a
     *  source file and outputs a series of terminal tokens to be fed into a
     *  parser. */
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
            /** Returns the terminal token type matched by this entry. */
            virtual TokenType getToken();
            /** Returns the regular expression that matches this entry. */
            virtual regex getRegex();
            /** Match this entry against the current string in the lexer, and
             *  store a matched string in match if one is found. Returns true
             *  if a match is found, and false otherwise. */
            virtual bool match(Lexer* lexer, string& match);
        private:
            /** The terminal token type matched by this entry. */
            TokenType token;
            /** The regular expression that matches this entry. */
            regex matcher;
    };

    struct MultilineLexerEntry : public LexerEntry {
        public:
            MultilineLexerEntry(TokenType token, regex startMatcher, regex matcher);
            /** Match this entry against the current string in the lexer, and
             *  store a matched string in match if one is found. Returns true
             *  if a match is found, and false otherwise. */
            virtual bool match(Lexer* lexer, string& match);
        private:
            /** The regular expression that starts matching this entry. */
            regex startMatcher;
    };

    class Lexer {
        /** LexerEntries need to be friends with lexer so that they can access
         *  the state of the lexer. */
        friend class LexerEntry;
        friend class MultilineLexerEntry;
        public:
            virtual ~Lexer();
            /** Open the given file named fileName and set up the lexer to
             *  analyse it. */
            virtual void openFile(string fileName);
            /** Close the currently open file, if there is one. */
            virtual void closeFile();
            /** Return true if the lexer currently has a file open, false
             *  otherwise. */
            virtual bool isOpen();
            /** Return true if the lexer currently has a file open and has
             *  reached the end of that file, false otherwise. */
            virtual bool isEOF();
            /** Return the lexer's current location in the currently open file,
             *  or error if no file is open. */
            // TODO implement errors
            virtual Location getLocation();
            /** Analyse the currently open file and return the next terminal
             *  token type found. Return the EOF token type if the lexer is
             *  at the end of the file. */
            virtual Token getToken();
            // Move these to LexerBuilder and add LexerBuilder as a friend.
            virtual void addToken(TokenType token, regex match);
            virtual void addToken(TokenType token, regex startMatch, regex match);
        private:
            /** Read a line from the open file and append it to the lexer's
             *  internal buffer. */
            virtual void readLine();
            /** Returns whether or not the lexer can read an additional line
             *  from the currently open file. */
            // This really isn't necessary and I should probably get rid of it
            virtual bool canReadLine();
            /** Returns the lexer's internal buffer. */
            // Also not necessary
            virtual string getCurrentLine();
            /** Make a backup of the lexer's internal state, including the
             *  buffer, line number, line offset, and file stream. */
            virtual void backupState();
            /** Restore the lexer's internal state from the most recent
             *  backup. */
            virtual void restoreState();
            /** Return true if the only characters left in the lexer's
             *  internal buffer are whitespace characters, false otherwise. */
            virtual bool isEndOfLine();
            /** Remove all leading whitespace characters from the lexer's
             *  internal buffer. */
            virtual void trimWhitespace();
            /** The LexerEntries comprising this lexer. */
            list<LexerEntry> entries;
            /** The current line number */
            int line;
            /** The current position on the current line. */
            int offset;
            /** The file currently being analysed. */
            ifstream file;
            /** The lexer's internal buffer. */
            string currentLine;
            /** Backup variables used by backupState and restoreState. */
            int oldLine;
            int oldOffset;
            streampos oldPos;
            string oldCurrentLine;
    };
}

#endif