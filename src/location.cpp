#include "location.h"

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