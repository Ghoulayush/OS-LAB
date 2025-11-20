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
    printf("This is the writer\n\n");
    int fd;
    if (mkfifo(FILE_NAME, 0666) == -1 && errno != EEXIST)
    { // Create FIFO if it doesn't exist
        perror("Error creating FIFO");
        return EXIT_FAILURE;
    }
    fd = open(FILE_NAME, O_WRONLY); // Open FIFO for writing
    if (fd == -1)
    {
        perror("Error opening FIFO for writing");
        return EXIT_FAILURE;
    }
    char msg[256];
    printf("Writer started. Type messages to send:\n");
    while (1)
    {
        printf("You: ");
        fflush(stdout);
        if (fgets(msg, sizeof(msg), stdin) != NULL)
        {
            msg[strcspn(msg, "\n")] = 0; // remove newline
            if (write(fd, msg, strlen(msg) + 1) == -1)
            {
                perror("Error writing to FIFO");
                break;
            }
        }
    }
    close(fd);
    return 0;
}
