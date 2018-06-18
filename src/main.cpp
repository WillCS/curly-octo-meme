#include "lexer.h"
#include "language.h"

using namespace curly_octo_meme;

int main(int argc, char** argv) {
    Lexer* lexer = constructLexer();

    lexer->openFile(argv[1]);
    while(!lexer->isEOF()) {
        cout << lexer->getToken()->getType() << '\n';
    }

    delete lexer;
    return 0;
}