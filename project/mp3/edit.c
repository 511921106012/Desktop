#include "header.h"

void edit_title(char *filename, char *new_title)
{
    if(new_title == NULL || strlen(new_title) == 0)
    {
        printf("Error: Title cannot be empty\n");
        return;
    }

    if(strlen(new_title) > 30)
    {
        printf("Error: Title too long (max 30 characters)\n");
        return;
    }

    FILE *fp = fopen(filename, "r+b");

    if(fp == NULL)
    {
        printf("Error: Unable to open file\n");
        return;
    }

    fseek(fp, -128, SEEK_END);
    char id[4] = {0};
    fread(id, 1, 3, fp);

    if(strcmp(id, "TAG") != 0)
    {
        printf("Error: No ID3v1 tag found in file\n");
        fclose(fp);
        return;
    }

    fseek(fp, -125, SEEK_END);

    char buffer[30] = {0};
    strncpy(buffer, new_title, 30);
    fwrite(buffer, 1, 30, fp);

    printf("\n✅ Title updated successfully!\n");
    printf("🎧 New Title : %s\n\n", new_title);

    fclose(fp);
}

void edit_comment(char *filename, char *new_comment)
{
    if(new_comment == NULL || strlen(new_comment) == 0)
    {
        printf("Error: Comment cannot be empty\n");
        return;
    }

    if(strlen(new_comment) > 28)
    {
        printf("Error: Comment too long (max 28 characters)\n");
        return;
    }

    FILE *fp = fopen(filename, "r+b");

    if(fp == NULL)
    {
        printf("Error: Unable to open file\n");
        return;
    }

    fseek(fp, -128, SEEK_END);
    char id[4] = {0};
    fread(id, 1, 3, fp);

    if(strcmp(id, "TAG") != 0)
    {
        printf("Error: No ID3v1 tag found\n");
        fclose(fp);
        return;
    }

    /* Comment offset: 3+30+30+30+4 = 97 bytes from TAG start
       From end: -128 + 97 = -31                              */
    fseek(fp, -31, SEEK_END);

    char buffer[30] = {0};
    strncpy(buffer, new_comment, 28);
    fwrite(buffer, 1, 30, fp);

    printf("\n✅ Comment updated successfully!\n");
    printf("💬 New Comment : %s\n\n", new_comment);

    fclose(fp);
}