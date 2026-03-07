#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_tags(char *filename);
void edit_title(char *filename, char *new_title);
void edit_comment(char *filename, char *new_comment);
void print_help();
int validate_mp3(char *filename);

#endif