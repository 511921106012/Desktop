#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

int my_copy(int source_fd, int dest_fd);

int main(int argc, char *argv[])
{
    int source_fd, dest_fd;
    int copy_permissions = 0;
    char *source_file, *dest_file;

    /* Check arguments */
    if (argc < 3)
    {
        printf("Insufficient arguments\n");
        printf("Usage: %s [-p] <source> <destination>\n", argv[0]);
        return 1;
    }

    /* Handle -p option */
    if (strcmp(argv[1], "-p") == 0)
    {
        if (argc != 4)
        {
            printf("Usage: %s [-p] <source> <destination>\n", argv[0]);
            return 1;
        }
        copy_permissions = 1;
        source_file = argv[2];
        dest_file = argv[3];
    }
    else
    {
        source_file = argv[1];
        dest_file = argv[2];
    }

    /* Open source file */
    source_fd = open(source_file, O_RDONLY);
    if (source_fd < 0)
    {
        perror("Error opening source file");
        return 1;
    }

    /* Check if destination exists */
    if (access(dest_file, F_OK) == 0)
    {
        printf("File \"%s\" already exists. Do you want to overwrite (Y/n): ", dest_file);
        char choice = getchar();

        if (choice == 'n' || choice == 'N')
        {
            printf("Operation cancelled.\n");
            close(source_fd);
            return 0;
        }
    }

    /* Open/Create destination file */
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0)
    {
        perror("Error opening/creating destination file");
        close(source_fd);
        return 1;
    }

    /* Perform copy */
    if (my_copy(source_fd, dest_fd) < 0)
    {
        printf("File copy failed\n");
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    /* Copy permissions if -p used */
    if (copy_permissions)
    {
        struct stat file_stat;
        if (fstat(source_fd, &file_stat) == -1)
        {
            perror("Error getting file permissions");
        }
        else
        {
            if (fchmod(dest_fd, file_stat.st_mode) == -1)
            {
                perror("Error setting file permissions");
            }
        }
    }

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
    return 0;
}

int my_copy(int source_fd, int dest_fd)
{
    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, BUF_SIZE)) > 0)
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            perror("Write error");
            return -1;
        }
    }

    if (bytes_read < 0)
    {
        perror("Read error");
        return -1;
    }

    return 0;
}