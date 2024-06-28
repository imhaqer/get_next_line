#include "get_next_line.h"
#include <stdio.h>
int main() 
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1) 
        return -1;

    while((line = get_next_line(fd)) > 0)
    {
         
       printf("%s", line); 
    }
        
    close(fd);

    return 0;
}

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"



int main() {
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Read lines until the end of file
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);  // Print or process the line as needed
        free(line);  // Free the line buffer allocated by get_next_line
    }

    close(fd);

    return 0;
}*/
