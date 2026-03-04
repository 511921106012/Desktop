#include <stdio.h>      // For printf()
#include <string.h>     // For strcmp()
#include "header.h"     // Custom header: contains print_help, view_tag, edit_tag declarations

int main(int argc, char *argv[])
{
    // If no command-line arguments are passed
    if (argc < 2)
    {
        print_help();   // Show help message
        return 1;       // Exit with error
    }

    /* Help option */
    // If user enters -h
    if (strcmp(argv[1], "-h") == 0)
    {
        print_help();   // Display help
        return 0;       // Exit successfully
    }

    /* View option */
    // If user enters -v
    if (strcmp(argv[1], "-v") == 0)
    {
        // -v needs exactly 3 arguments: program -v mp3file
        if (argc != 3)
        {
            printf("Usage: %s -v <mp3file>\n", argv[0]);
            return 1;
        }
        view_tag(argv[2]);  // Call function to view MP3 tag
        return 0;
    }

    /* Edit option */
    // If user enters -e
    if (strcmp(argv[1], "-e") == 0)
    {
        // -e needs exactly 5 arguments
        if (argc != 5)
        {
            printf("Usage: %s -e <mp3file> -t|-a|-A|-y|-g|-c \"value\"\n", argv[0]);
            return 1;
        }

        char tag_opt;   // Variable to store tag option

        // Check which tag user wants to edit
        if      (strcmp(argv[3], "-t") == 0) tag_opt = 't'; // Title
        else if (strcmp(argv[3], "-a") == 0) tag_opt = 'a'; // Artist
        else if (strcmp(argv[3], "-A") == 0) tag_opt = 'A'; // Album
        else if (strcmp(argv[3], "-y") == 0) tag_opt = 'y'; // Year
        else if (strcmp(argv[3], "-g") == 0) tag_opt = 'g'; // Genre
        else if (strcmp(argv[3], "-c") == 0) tag_opt = 'c'; // Comment
        else
        {
            printf("Invalid tag option\n"); // Wrong option entered
            return 1;
        }

        // Call function to edit the selected tag
        edit_tag(argv[2], tag_opt, argv[4]);
        return 0;
    }

    // If none of the valid options matched
    print_help();
    return 1;
}
