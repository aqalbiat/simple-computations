import os

FLAGS = " --std=c++14 -Wall --pedantic-errors "

BUILD_LEXER = f"g++ ./lexing/main.cpp -o ./bin/main {FLAGS}"

RUN_LEXER = "./bin/main"

commands = []
commands.append(BUILD_LEXER)
commands.append(RUN_LEXER)

for cmd in commands:
    os.system(cmd)

