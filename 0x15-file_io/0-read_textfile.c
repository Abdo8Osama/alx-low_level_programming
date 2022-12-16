#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - A function that reads a text file and prints
 * to the POSIX STDOUT
 * @filename: The filename to open
 * @letters: The number of letters to read and print
 * Return: The number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdo;
	ssize_t printed = 0;                                      
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fdo = open(filename, O_RDONLY);
	if (fdo < 0)
	{
		free(buf);
		return (0);
	}

	fdr = read(fdo, buf, letters);
	if (fdr < 0)
	{
		free(buf);
		return (0);
	}

	fdw = write(STDOUT_FILENO, buf, fdr);
	free(buf);
	close(fdo);

	if (fdw < 0)
		return (0);
	return ((ssize_t)fdw);
}
