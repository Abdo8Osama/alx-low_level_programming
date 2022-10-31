#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads text file and prints it
 *@letters: number of letters should read and print 
 *@filename: file name to read
 *
 *Return: number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int printed = 0;
	char buf[letters+1];
	
	if(filename == NULL)
		return (0);
	
	fd = open(filename, O_RDONLY);
	
	if(fd == -1)
		return (0);
	
	read(fd, buf, letters);
	buf[letters] = '\0';
	while(*buf)
	{
		printed += _putchar(*buf);
		buf++;
	}
	
	close(fd);
	
	return printed;
}
