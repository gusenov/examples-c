#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang `find . -maxdepth 1 -name "*.c" | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"
