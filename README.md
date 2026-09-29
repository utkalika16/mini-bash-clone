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
## Week 5 Features

- Built-in command support
- `cd`
- `pwd`
- `help`
- `clear`
- `exit`
- Environment variable support using `getenv()`

## Week 5 Architecture

```text
User Input
    ↓
read_line()
    ↓
parse_line()
    ↓
Check Built-in Command
    ↓
┌───────────────┐
│ Built-in?     │
└───────┬───────┘
        │
   ┌────┴────┐
   YES       NO
    ↓         ↓
builtin.c   process.c
    ↓         ↓
Parent      fork()
process       ↓
            execvp()
## Week 6 - Signals and Process Control

### Objective

Week 6 extends Mini Bash Clone with signal handling and basic process control.

The shell is designed to handle signals safely so that pressing `Ctrl+C` does not terminate the shell itself.

### Week 6 Features

- Signal handling using `signal()`
- `SIGINT` handling for `Ctrl+C`
- `SIGCHLD` handling for completed child processes
- Zombie process cleanup using `waitpid()`
- Shell continues running after `Ctrl+C`
- Integration of signal handling into the main shell loop

### Signal Flow

```text
User
  |
  | Ctrl+C
  v
SIGINT
  |
  v
sigint_handler()
  |
  v
Shell remains running
  |
  v
myshell>
## Week 7 - Pipes and Inter-Process Communication

### Objective

Week 7 extends Mini Bash Clone with anonymous pipe support for inter-process communication (IPC).

The shell can now execute two commands connected using the `|` operator.

### Week 7 Features

- Anonymous pipes using `pipe()`
- Inter-process communication (IPC)
- Two-stage command pipelines
- Input/output redirection using `dup2()`
- Process creation using `fork()`
- Command execution using `execvp()`
- Pipe operator `|`
- Parent process waits for both child processes
- Integration with existing signal handling and command execution

### Pipe Architecture

```text
Command 1
   |
   | stdout
   v
pipe()
   |
   | kernel pipe
   v
Command 2
   |
   | stdin
   v
Terminal
## Week 8 - Memory Management, Debugging, and Valgrind

### Objective

Week 8 focuses on memory management, debugging, and improving the reliability of Mini Bash Clone.

The project was tested using Valgrind, GDB, and AddressSanitizer (ASan).

### Week 8 Features

- Memory leak detection using Valgrind
- Debugging using GDB
- AddressSanitizer support
- Defensive memory management
- Improved resource cleanup
- Debugging symbols using `-g`
- Memory-safe shell execution

### Memory Management

Mini Bash Clone dynamically allocates memory for:

- Command input buffers
- Command argument arrays
- Parsed command data

All dynamically allocated memory is properly released after use.

The `exit` command was updated so that allocated input and token memory is freed before the shell terminates.

### Valgrind Testing

The shell was tested using:

```text
valgrind --leak-check=full --show-leak-kinds=all ./bin/bashclone
