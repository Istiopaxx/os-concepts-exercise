#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZ 4096

int main()
{
    int source_fd, target_fd, n;

    char source_path[100], target_path[100], buffer[BUFSIZ];
    printf("Enter the source file path to copy: ");
    scanf("%s", source_path);
    if ((source_fd = open(source_path, O_RDONLY)) < 0)
    {
        printf("Error to open file.\n");
        exit(1);
    }
    printf("Enter the target file path to copy to: ");
    scanf("%s", target_path);
    if ((target_fd = open(target_path, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
    {
        printf("Error creating file.\n");
        exit(1);
    }

    while ((n = read(source_fd, buffer, BUFSIZ)) > 0)
    {
        if (write(target_fd, buffer, n) < 0)
        {
            printf("Error writing to file.\n");
            exit(1);
        }
    }

    return 0;
}
