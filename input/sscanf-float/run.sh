#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang main.c -o "$EXE_FILE" && "$EXE_FILE"
