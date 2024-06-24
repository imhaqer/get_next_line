/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char *fileName = "text.txt";
    int fd =  open(fileName, O_RDONLY);

    if (fd == -1)
    {
        printf("Error opening File\n");
        return -1;
    }

    char *buffer = calloc(100, sizeof(char));
    if (!buffer)
    {
        printf("Error allocatig memory!");
        close(fd);
        return -1;
    }

    int bytesRead;
    int count = 0;
    while (bytesRead = read(fd, buffer, 10))
    {
        // printf("%d\n", bytesRead);
        buffer[bytesRead] = '\0';
        count ++;
        printf("[%d] %s\n", count, buffer);
    }

    if (bytesRead == -1)
    {
        return -1;
    }

      

    free(buffer);
    close (fd);
    return 0;
}*/


