SRC_DIR = "src"
function SRC(filename)
    return SRC_DIR .. "/" .. filename
end

LANG_DIR = "src/lua"
function LANG(filename)
    return LANG_DIR .. "/" .. filename
end

COMPILER_ARGS = "-pedantic -Wall -std=gnu++17 -I/" .. SRC_DIR

OUTPUT_DIR = "bin"
function OUTPUT(filename)
    return OUTPUT_DIR .. "/" .. filename
end

task({
    name = "build",
    dependencies = {
        "main.o", "queue.o", "lexer.o", "location.o", "token.o", "language.o"
    },
    action = shell("g++",
        "-o", OUTPUT("main"),
        OUTPUT("main.o"),
        OUTPUT("queue.o"),
        OUTPUT("location.o"),
        OUTPUT("token.o"),
        OUTPUT("lexer.o"),
        OUTPUT("language.o"))
})

task({
    name = "language.o",
    dependency = SRC("language.cpp"),
    action = shell("g++",
        "-o", OUTPUT("language.o"), 
        "-c", SRC("language.cpp"), 
        COMPILER_ARGS)
})

task({
    name = "lexer.o",
    dependency = SRC("lexer.cpp"),
    action = shell("g++",
        "-o", OUTPUT("lexer.o"), 
        "-c", SRC("lexer.cpp"), 
        COMPILER_ARGS)
})

task({
    name = "main.o",
    dependency = SRC("main.cpp"),
    action = shell("g++",
        "-o", OUTPUT("main.o"), 
        "-c", SRC("main.cpp"), 
        COMPILER_ARGS)
})

task({
    name = "queue.o",
    dependency = SRC("queue.cpp"),
    action = shell("g++",
        "-o", OUTPUT("queue.o"), 
        "-c", SRC("queue.cpp"), 
        COMPILER_ARGS)
})

task({
    name = "location.o",
    dependency = SRC("location.cpp"),
    action = shell("g++",
        "-o", OUTPUT("location.o"), 
        "-c", SRC("location.cpp"), 
        COMPILER_ARGS)
})

task({
    name = "token.o",
    dependency = SRC("token.cpp"),
    action = shell("g++",
        "-o", OUTPUT("token.o"), 
        "-c", SRC("token.cpp"), 
        COMPILER_ARGS)
})

task({
    name = "clean",
    action = shell("rm", "--force", OUTPUT("*"))
})