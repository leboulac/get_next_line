*This project has been created as part of the 42 curriculum by jgaine.*

## Description

Get Next Line is a project that consists of creating a function in C that reads and returns one line from a file each time the function is called.

## Algorithm

The `get_next_line()` function retrieves one line from a file each time it is called.

To achieve this, it uses a static variable called `keep`, which stores characters that have already been read but have not yet been returned. This variable allows these characters to be reused during the next function call.

Reading is performed by `gnl_read()` using the `read()` function. Each call to `read()` reads up to `BUFFER_SIZE` bytes. A loop is necessary because a single call to `read()` does not guarantee that a complete line will be retrieved. The characters read are appended to `keep` until a newline character (`\n`) is found or the end of the file is reached.

During concatenation, a temporary variable called `tmp` is used to store the address of the new string. This makes it possible to check whether the memory allocation was successful before freeing the previous `keep`, preventing memory leaks.

The `extract_line()` function creates a new string containing only the line to be returned. This allocation separates the line from the contents of `keep`, allowing their memory to be managed independently.

Next, `gnl_rest()` keeps the characters located after the newline character (`\n`) in `keep`. These characters belong to the next line and must not be lost because `read()` will not read them again.

Finally, if a reading error occurs, the allocated memory is freed before returning `NULL` to prevent memory leaks.

## Instructions

To test the project, a `main.c` file can be used to call `get_next_line()` and read a text file.

### Example of main.c

Here is an example program to test `get_next_line()`:

```c
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

This program:

1. Opens the `test.txt` file in read-only mode using `open()`.
2. Calls `get_next_line()` to retrieve the first line.
3. Displays each line using `printf()`.
4. Frees the memory allocated for each line using `free()`.
5. Continues until `get_next_line()` returns `NULL`.
6. Closes the file descriptor using `close()`.

Each line returned by `get_next_line()` is dynamically allocated. Therefore, it must be freed after use to prevent memory leaks.

### Compilation

To compile the program with the required flags:

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl
```

It is also possible to define the buffer size during compilation using the `-D` option. For example, to use a buffer size of 6 bytes:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=6 main.c get_next_line.c get_next_line_utils.c -o gnl
```

If no value is specified, `BUFFER_SIZE` is set to 4 by default.

To run the program, place a `test.txt` file in the same directory and execute:

```bash
./gnl
```

## Resources

To complete this project, I used several resources:

- YouTube videos to better understand how `get_next_line()` works.
- Websites to improve my knowledge of the C programming language.
- ChatGPT to help me understand certain concepts, including reading with `read()`, static variables, memory allocation, and error handling. AI also helped me think through my algorithm and write this README.