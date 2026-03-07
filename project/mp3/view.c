#include "header.h"

/* Genre names */
char *genres[] = {
"Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge",
"Hip-Hop","Jazz","Metal","New Age","Oldies","Other","Pop","R&B",
"Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska"
};

void view_tags(char *filename)
{
    FILE *fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Error: Unable to open file\n");
        return;
    }

    /* Check file size */
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if(size < 128)
    {
        printf("Invalid MP3 file\n");
        fclose(fp);
        return;
    }

    /* Move to ID3v1 tag */
    fseek(fp, -128, SEEK_END);

    char id[4] = {0};
    fread(id, 1, 3, fp);

    if(strcmp(id, "TAG") != 0)
    {
        printf("No ID3v1 tag found\n");
        fclose(fp);
        return;
    }

    /* Declare fields with +1 byte for null terminator */
    char title[31]  = {0};
    char artist[31] = {0};
    char album[31]  = {0};
    char year[5]    = {0};

    fread(title,  1, 30, fp);
    fread(artist, 1, 30, fp);
    fread(album,  1, 30, fp);
    fread(year,   1, 4,  fp);

    /* Read comment block once into buffer */
    unsigned char buffer[30] = {0};
    fread(buffer, 1, 30, fp);

    char comment[29] = {0};
    memcpy(comment, buffer, 28);
    comment[28] = '\0';

    /* Read genre byte */
    unsigned char genre = 0;
    fread(&genre, 1, 1, fp);

    /* Null terminate strings safely */
    title[30]  = '\0';
    artist[30] = '\0';
    album[30]  = '\0';
    year[4]    = '\0';

    printf("\n\n   🤠 Viewing MP3 Tags for 🎼 : %s\n", filename);
    printf("   ------------------------------------\n\n");

    printf("🎧 Title   : %s\n\n", strlen(title)  ? title  : "Not Available");
    printf("🎤 Artist  : %s\n\n", strlen(artist) ? artist : "Not Available");
    printf("💿 Album   : %s\n\n", strlen(album)  ? album  : "Not Available");
    printf("📅 Year    : %s\n\n", strlen(year)   ? year   : "Not Available");

    /* Only show comment if it has more than 3 meaningful characters */
    if(strlen(comment) > 3)
        printf("💬 Comment : %s\n\n", comment);
    else
        printf("💬 Comment : Not Available\n\n");

    /* genre < 22 includes all 22 genres (index 0-21) */
    if(genre < 22)
        printf("🎼 Genre   : %s\n\n", genres[genre]);
    else
        printf("🎼 Genre   : Not Available\n\n");

    fclose(fp);
}