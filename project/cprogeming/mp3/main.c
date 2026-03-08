#include "header.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        print_help();
        return 0;
    }

    if(argc < 3)
    {
        printf("Error: No file specified\n");
        print_help();
        return 0;
    }

    if(validate_mp3(argv[2]) == 0)
    {
        printf("Error: Only .mp3 files allowed\n");
        return 0;
    }

    if(strcmp(argv[1], "-v") == 0)
    {
        view_tags(argv[2]);
    }
    else if(strcmp(argv[1], "-e") == 0)
    {
        if(argc < 4)
        {
            printf("Error: Missing title value\n");
            printf("Usage: mp3 -e <file.mp3> <new_title>\n");
            return 0;
        }
        edit_title(argv[2], argv[3]);
    }
    else if(strcmp(argv[1], "-c") == 0)
    {
        if(argc < 4)
        {
            printf("Error: Missing comment value\n");
            printf("Usage: mp3 -c <file.mp3> <new_comment>\n");
            return 0;
        }
        edit_comment(argv[2], argv[3]);
    }
    else
    {
        printf("Error: Unknown option '%s'\n", argv[1]);
        print_help();
    }

    return 0;
}