*This project has been created as part of the 42 curriculum by jgaine.*

# get_next_line

## Description

**get_next_line** is a project from the 42 curriculum.

The goal is to implement a function in C that reads and returns one line at a time from a file descriptor.

This project introduces important concepts such as:

- File descriptors and the `read()` function
- Static variables
- Dynamic memory allocation
- Buffer management
- Memory management and error handling

## Function Prototype

```c
char *get_next_line(int fd);
```

The function reads from the given file descriptor and returns the next available line.

- Each call returns one line.
- The returned line includes the newline character (`\n`) when present.
- The last line is returned even if it does not end with `\n`.
- The function returns `NULL` when there is nothing left to read or when an error occurs.

The returned string is dynamically allocated and must be freed by the caller.

## Project Files

```text
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

### File descriptions

**get_next_line.c**

Contains the main function and the logic for reading, storing, and extracting lines.

**get_next_line_utils.c**

Contains helper functions used for string manipulation and memory management.

**get_next_line.h**

Contains the function prototypes, required libraries, and the default `BUFFER_SIZE` definition.

## Compilation

The project can be compiled using `cc` with the required flags:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o test_gnl
```

`main.c` is a separate test file and is not part of the mandatory submission.

The `BUFFER_SIZE` value can be changed during compilation.

If no value is provided, the project uses a default buffer size defined in `get_next_line.h`.

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
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

The function can also read from standard input:

```c
char *line = get_next_line(0);
```

## How It Works

The function uses a **static variable** to preserve unread data between calls.

1. Read data from the file descriptor using `read()`.
2. Store the data in a dynamically allocated string.
3. Continue reading until a newline is found or the end of the file is reached.
4. Extract and return the next line.
5. Keep any remaining data for the next function call.
6. Free allocated memory when it is no longer needed.

This approach allows the function to return one line at a time without losing unread data.

## Resources

During the development of this project, I used several resources to improve my understanding of C programming and the concepts behind `get_next_line`:

- **YouTube videos:** To better understand file descriptors, the `read()` function, static variables, and memory management.
- **GitHub:** To explore different approaches and understand how other developers structure their projects.
- **Programming forums:** To find explanations, discuss common issues, and understand potential errors.
- **ChatGPT:** To clarify C concepts, prepare test cases, debug issues, and check memory management.

These resources helped me improve my understanding of the project and develop my own implementation.