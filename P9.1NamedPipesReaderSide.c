#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define FILE_NAME "/tmp/myfifo"
int main()
{
    printf("P9: IMPLEMENTATION OF NAMED PIPES, FIFO.\n");
    printf("This is the reader\n\n");
    int fd;
    char buffer[256];
    fd = open(FILE_NAME, O_RDONLY); // Open FIFO for reading
    if (fd == -1)
    {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }
    printf("Reader started. Waiting for messages...\n");
    while (1)
    {
        memset(buffer, 0, sizeof(buffer)); // clear buffer
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
        if (bytesRead > 0)
        {
            printf("Reader: Message received -> %s\n", buffer);
        }
        else if (bytesRead == 0)
        {
            // Writer closed, reopen
            close(fd);
            fd = open(FILE_NAME, O_RDONLY);
            if (fd == -1)
            {
                perror("Error reopening FIFO");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            perror("Error reading from FIFO");
            break;
        }
    }
    close(fd);
    return 0;
}
