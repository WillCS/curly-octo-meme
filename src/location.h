#ifndef LOCATION
#define LOCATION

namespace curly_octo_meme {
    struct Location {
        public:
            Location(int line, int offset);
            virtual int getLine();
            virtual int getOffset();
        private:
            int line;
            int offset;
    };
}

#endif