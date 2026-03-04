*This project has been created as part of the 42 curriculum by mozay.*

# Libft

## Description

Libft is a custom static C library developed as part of the 42 curriculum.  
The goal of this project is to recreate a selection of standard C library functions and to implement additional utility functions that will be reused in future projects.

By reimplementing these functions from scratch, the project strengthens understanding of:
- Low-level programming in C
- Memory management and allocation
- Pointer arithmetic
- Defensive programming and edge-case handling
- Creation and use of static libraries

Libft serves as a personal foundational library throughout the 42 cursus.

---

## Library Overview

The library is composed of several groups of functions, each focusing on a specific area of C programming.

### Character handling
Functions used to test or convert individual characters.

- `ft_isalpha` — Checks whether a character is an alphabetical letter.
- `ft_isdigit` — Checks whether a character is a digit (0–9).
- `ft_isalnum` — Checks whether a character is alphanumeric.
- `ft_isascii` — Checks whether a character belongs to the ASCII table.
- `ft_isprint` — Checks whether a character is printable.
- `ft_tolower` — Converts an uppercase letter to lowercase.
- `ft_toupper` — Converts a lowercase letter to uppercase.

---

### String manipulation
Functions for handling and transforming null-terminated strings.

- `ft_strlen` — Returns the length of a string.
- `ft_strdup` — Allocates and returns a duplicate of a string.
- `ft_strchr` — Locates the first occurrence of a character in a string.
- `ft_strrchr` — Locates the last occurrence of a character in a string.
- `ft_strncmp` — Compares two strings up to `n` characters.
- `ft_strlcpy` — Copies a string with size limitation.
- `ft_strlcat` — Concatenates strings with size limitation.
- `ft_strnstr` — Locates a substring within a string, limited by length.
- `ft_substr` — Extracts a substring from a string.
- `ft_strjoin` — Concatenates two strings into a new allocated string.
- `ft_strtrim` — Trims specified characters from the beginning and end of a string.
- `ft_split` — Splits a string into an array of strings using a delimiter.
- `ft_itoa` — Converts an integer into a string.
- `ft_strmapi` — Applies a function to each character of a string and creates a new string.
- `ft_striteri` — Applies a function to each character of a string in place.

---

### Memory management
Low-level functions for raw memory manipulation.

- `ft_memset` — Fills a block of memory with a specific value.
- `ft_bzero` — Sets a block of memory to zero.
- `ft_memcpy` — Copies memory from one area to another (no overlap handling).
- `ft_memmove` — Copies memory safely, handling overlapping areas.
- `ft_memchr` — Searches for a byte in a block of memory.
- `ft_memcmp` — Compares two memory areas.
- `ft_calloc` — Allocates memory and initializes it to zero.

---

### File descriptor output
Functions that write data to a given file descriptor.

- `ft_putchar_fd` — Writes a single character to a file descriptor.
- `ft_putstr_fd` — Writes a string to a file descriptor.
- `ft_putendl_fd` — Writes a string followed by a newline.
- `ft_putnbr_fd` — Writes an integer to a file descriptor.

---

### Linked list utilities
Functions to manipulate singly linked lists.

- `ft_lstnew` — Creates a new list element.
- `ft_lstadd_front` — Adds an element at the beginning of a list.
- `ft_lstadd_back` — Adds an element at the end of a list.
- `ft_lstsize` — Counts the number of elements in a list.
- `ft_lstlast` — Returns the last element of a list.
- `ft_lstdelone` — Deletes a single list element.
- `ft_lstclear` — Deletes and frees an entire list.
- `ft_lstiter` — Applies a function to each element of a list.
- `ft_lstmap` — Creates a new list by applying a function to each element.

---

## Detailed Library Description

Libft faithfully reimplements standard C library functions while respecting their original behavior and limitations.  
Each function is designed to handle edge cases safely and to avoid undefined behavior whenever possible.

Memory allocation and deallocation are handled carefully to prevent leaks.  
The linked list bonus provides a minimal yet complete API to manage dynamic data structures.

This library is intended to be reused and extended in future projects.

---

## Instructions

The project uses a **Makefile** to manage compilation.

Available commands:

- **`make`** or **`make all`**  
  Compiles the source files and generates the static library `libft.a`.

- **`make clean`**  
  Removes object files (`.o`).

- **`make fclean`**  
  Removes object files and the compiled library.

- **`make re`**  
  Rebuilds the project from scratch.

---

## Resources

- **Official 42 Documentation** – For project guidelines and submission criteria: [42 GitHub](https://github.com/42School)  
- **C Standard Library Documentation** – Manual pages and online resources, especially for `string.h`, `stdlib.h`, and `unistd.h` functions.  
- **Learn C The Hard Way** – Exercises and implementation examples for C functions: Zed A. Shaw, 2015.  
- **GeeksforGeeks / TutorialsPoint** – Detailed explanations of string and memory manipulation functions.  
- **42 Network Forums & Peer Reviews** – Code examples and optimization advice from the 42 community.

## AI Usage

Artificial intelligence was used in the project for the following purposes:  
  
1. **Debugging and suggestions** – AI helped identify potential logical errors and offered suggestions to improve code readability.  
2. **Writing the README.md** – AI assisted in structuring and phrasing the README.md sections, including this "Resources" and "AI Usage" content.

---


### Usage example

1. Compile the library:
   ```bash
   make
