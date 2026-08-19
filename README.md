## Week 2 Features

- Dynamic command input
- Memory allocation using malloc()
- Automatic buffer expansion using realloc()
- Proper memory cleanup using free()
- Modular input handling using input.h and input.c

## Week 2 Architecture

The shell now uses a dynamically allocated input buffer.

User Input
    ↓
read_line()
    ↓
malloc()
    ↓
realloc() when buffer is full
    ↓
Command returned to main.c
    ↓
free() after use# Mini Bash Clone

Mini Bash Clone is a simplified Unix-like shell developed in C as part of the Operating Systems and Systems Programming course.

## Features (Week 1)

- Interactive REPL loop
- Makefile-based build
- Git repository
- Linux development environment

## Build

```bash
make
