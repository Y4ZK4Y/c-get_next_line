# get_next_line

## Overview
get_next_line is part of the core curriculum of Codam College, and it's a fundamental exercise in handling file descriptors for reading text files line by line. It emphasizes efficient memory management, proper use of external functions, and the intricacies of file reading in C programming.

## Behavior
Undefined behavior if the file descriptor's file changes between calls.

Undefined behavior when reading a binary file (optional logical handling can be implemented).

Must work with a wide range of BUFFER_SIZE values, from very small (1) to very large (e.g., 10000000).



## Key Features
- **Efficiency**: Designed to read as little as possible on each call, optimizing for memory and processing efficiency.
- **Compatibility**: Works with both file reading and standard input.
- **Flexibility**: Supports compilation with variable buffer sizes, allowing for testing under different conditions.

## Compilation
The project must be compilable with the `-D BUFFER_SIZE=n` flag to define the buffer size for the `read()` function, alongside standard flags (`-Wall -Wextra -Werror`).

This ensures flexibility in handling files of different sizes and characteristics.

## Constraints
- No use of any external library.
- `lseek()` is forbidden, emphasizing sequential reading without seeking.
- Global variables are prohibited, promoting good coding practices.





