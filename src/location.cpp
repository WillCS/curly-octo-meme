#include "location.h"

using namespace curly_octo_meme;

Location::Location(int line, int offset) {
    this->line = line;
    this->offset = offset;
}

int Location::getLine() {
    return this->line;
}

int Location::getOffset() {
    return this->offset;
}