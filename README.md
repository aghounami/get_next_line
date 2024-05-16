# Get Next Line

## Goals

This project is focused on programming a function that returns a line read from a file descriptor. It provides an opportunity to learn about static variables in C programming.

## Common Instructions

- The project must be written in C and must adhere to the Norm.
- Functions should not quit unexpectedly, and memory should be properly managed to avoid leaks.
- If required, include a Makefile that compiles with the flags `-Wall`, `-Wextra`, and `-Werror`.
- The Makefile must contain rules for `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- If your project includes bonus functionalities, they should be separated from the mandatory part and evaluated separately.
- If you use your `libft`, include its sources and Makefile in a `libft` folder. Your project's Makefile should compile the library by using its Makefile.
- It's recommended to create test programs for your project to facilitate testing during development and defense.

## Mandatory Part

### Function Name
`get_next_line`

### Prototype
```c
char *get_next_line(int fd);
 ```
# Turn-in Files
get_next_line.c, get_next_line_utils.c, get_next_line.h

# Parameters
fd: The file descriptor to read from
# Return Value
Read line: Correct behavior
NULL: There is nothing else to read, or an error occurred
External Functions Allowed
read, malloc, free

# Description
Write a function that returns a line read from a file descriptor.

- Repeated calls to get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
- Ensure that your function works as expected both when reading a file and when reading from the standard input.
- The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- Your header file get_next_line.h must contain at least the prototype of the get_next_line() function.
- Add all the helper functions you need in the get_next_line_utils.c file.
# Bonus Part
This project doesn’t allow complex bonuses, but you can try the following:

- Develop get_next_line() using only one static variable.
- Manage multiple file descriptors at the same time.
. Append the _bonus.[c/h] suffix to the bonus part files.

. The bonus part will only be assessed if the mandatory part is perfect.

# Submission and Peer-evaluation
Submit your assignment to your Git repository. Only the work inside your repository will be evaluated during the defense. Double-check the names of your files to ensure they are correct.

When writing your tests, remember that:

1- Both the buffer size and the line size can be of very different values.
2- A file descriptor does not only point to regular files.
