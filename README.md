# Mini Bash Clone

Mini Bash Clone is a simplified Unix-like shell developed in C as part of the Operating Systems and Systems Programming (OSSP) project.

## Features (Week 1)

- Interactive REPL loop
- Makefile-based build
- Git repository
- Linux development environment

## Build

```bash
make
Week 2 Features
Dynamic command input
Memory allocation using malloc()
Automatic buffer expansion using realloc()
Proper memory cleanup using free()
Modular input handling using input.h and input.c
Week 2 Architecture

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
free() after use
Week 3 Features
Command parsing using strtok()
Dynamic argv[] construction
Modular parser implementation
Ready for process execution with execvp()
Week 3 Architecture

The shell now parses user commands into tokens.

User Input
    ↓
read_line()
    ↓
parse_line()
    ↓
strtok()
    ↓
argv[] tokens
    ↓
Ready for execvp()

Then:

**Ctrl + O** → **Enter** → **Ctrl + X**

After exiting nano, run:

```bash
cat README.md

That's the complete corrected README.

give only wt i ned to copy in it
# Mini Bash Clone

Mini Bash Clone is a simplified Unix-like shell developed in C as part of the Operating Systems and Systems Programming (OSSP) project.

## Features (Week 1)

- Interactive REPL loop
- Makefile-based build
- Git repository
- Linux development environment

## Build

```bash
make
Week 2 Features
Dynamic command input
Memory allocation using malloc()
Automatic buffer expansion using realloc()
Proper memory cleanup using free()
Modular input handling using input.h and input.c
Week 2 Architecture

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
free() after use
Week 3 Features
Command parsing using strtok()
Dynamic argv[] construction
Modular parser implementation
Ready for process execution with execvp()
Week 3 Architecture

The shell now parses user commands into tokens.

User Input
    ↓
read_line()
    ↓
parse_line()
    ↓
strtok()
    ↓
argv[] tokens
    ↓
Ready for execvp()
## Week 4 Features

- Process creation using fork()
- Command execution using execvp()
- Parent-child synchronization using waitpid()
- Error handling using perror()
