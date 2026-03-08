#include "header.h"

void print_help()
{
    printf("\nUsage:\n");
    printf("./mp3 -v <file.mp3>                -> View MP3 tags\n");
    printf("./mp3 -e <file.mp3> <new_title>    -> Edit title\n");
    printf("./mp3 -c <file.mp3> <new_comment>  -> Edit comment\n\n");
}

int validate_mp3(char *filename)
{
    char *ext = strrchr(filename, '.');

    if(ext && strcmp(ext, ".mp3") == 0)
        return 1;

    return 0;
}