#include "lexer.h"

using namespace curly_octo_meme;

const std::regex eolMatcher("^\\s*$");
const std::regex wsMatcher("^\\s*");

/* LexerEntry methods *****************/

LexerEntry::LexerEntry(TokenType token, regex matcher) {
    this->token = token;
    this->matcher = matcher;
}

TokenType LexerEntry::getToken() {
    return this->token;
}

regex LexerEntry::getRegex() {
    return this->matcher;
}

bool LexerEntry::match(Lexer* lexer, string& match) {
    std::smatch found;
    string search = lexer->getCurrentLine();
    std::regex_search(search, found, this->getRegex());
    if(!found.empty()) {
        match = found[0];
        return true;
    }

    return false;
}

/* MultilineLexerEntry methods *******/

MultilineLexerEntry::MultilineLexerEntry(TokenType token, regex startMatcher, 
        regex matcher) : LexerEntry(token, matcher) {
    this->startMatcher = startMatcher;
}

bool MultilineLexerEntry::match(Lexer* lexer, string& match) {
    std::smatch foundStart;
    string startSearch = lexer->getCurrentLine();
    std::regex_search(startSearch, foundStart, this->startMatcher);

    if(!foundStart.empty()) {
        lexer->backupState();
        std::smatch found;
        while(!lexer->isEOF()) {
            string search = lexer->getCurrentLine();
            std::regex_search(search, found, this->getRegex());

            if(!found.empty()) {
                match = found[0];
                return true;
            } else if(lexer->canReadLine()) {
                lexer->readLine();
                continue;
            } else {
                lexer->restoreState();
                return false;
            }
        }
    } 

    return false;
}

/* Lexer methods **********************/

Lexer::~Lexer() {
    if(this->isOpen()) {
        this->closeFile();
    }
}

void Lexer::openFile(string fileName) {
    if(this->file.is_open()) {
        this->closeFile();
    }

    this->file.open(fileName);
    this->readLine();
}

void Lexer::closeFile() {
    this->file.close();
}

bool Lexer::isOpen() {
    return this->file.is_open();
}

bool Lexer::isEndOfLine() {
    std::smatch match;
    std::regex_search(this->currentLine, match, eolMatcher);
    return !match.empty();
}

bool Lexer::isEOF() {
    return this->file.eof() && this->isEndOfLine();
}

bool Lexer::canReadLine() {
    return !this->file.eof();
}

void Lexer::trimWhitespace() {
    std::smatch match;
    std::regex_search(this->currentLine, match, wsMatcher);
    if(!match.empty() && match[0].length() != 0) {
        this->currentLine = this->currentLine.substr(match[0].length());
        this->offset += match[0].length();
    }
}

void Lexer::readLine() {
    if(this->isOpen()) {
        string newLine;
        std::getline(this->file, newLine);
        this->currentLine.append(newLine);
        this->currentLine.append("\n");
        this->line++;
        this->offset = 1;
    }
}

Location Lexer::getLocation() {
    Location loc(this->line, this->offset);
    return loc;
}

string Lexer::getCurrentLine() {
    return this->currentLine;
}

void Lexer::backupState() {
    this->oldLine = this->line;
    this->oldOffset = this->offset;
    this->oldPos = this->file.tellg();
    this->oldCurrentLine = this->currentLine;
}

void Lexer::restoreState() {
    this->line = this->oldLine;
    this->offset = this->oldOffset;
    this->file.clear();
    this->file.seekg(this->oldPos);
    this->currentLine = this->oldCurrentLine;
}

Token Lexer::getToken() {
    while(this->isEndOfLine()) {
        this->readLine();
        if(this->isEOF()) {
            Location loc = this->getLocation();
            return Token(TokenType::END_OF_FILE, loc);
        }
    }

    this->trimWhitespace();
    Location loc = this->getLocation();

    string matchedToken;
    for(auto& entry : this->entries) {
        if(entry.match(this, matchedToken)) {
            this->currentLine = this->currentLine.substr(matchedToken.length());
            this->offset += matchedToken.length();
            TokenType type = entry.getToken();
            switch(type) {
                case IDENTIFIER_TOKEN_TYPE:
                    return getIdentifierToken(matchedToken, loc);
                    break;
                case STRING_TOKEN_TYPE:
                    return getStringToken(matchedToken, loc);
                    break;
                case NUMBER_TOKEN_TYPE:
                    return getNumberToken(matchedToken, loc);
                    break;
                default:
                    return Token(type, loc);
                    break;
            }
            break;
        }
    }
    cout << "The bad thing is happening\n";
    // This should never happen
    return Token(TokenType::INVALID, loc);
}

void Lexer::addToken(TokenType token, regex match) {
    this->entries.push_back(LexerEntry(token, match));
}

void Lexer::addToken(TokenType token, regex startMatch, regex match) {
    this->entries.push_back(MultilineLexerEntry(token, startMatch, match));
}
