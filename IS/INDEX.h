#ifndef INDEX
#define INDEX

#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct file_name
{
    char file_name[20];
    struct file_name *link;
}file_list;

typedef struct Sub
{
    int word_count;
    char filename[20];
    struct Sub *next_sub;
}Sub_list;

typedef struct Main
{
    int file_count;
    char word[20];
    Sub_list *sub_link;
    struct Main *main_link;
}Main_list;

typedef struct hasttable
{
    int index;
    Main_list *next_main;
}Hash;



//int read_validation(int argc, char *argv[], file_list **files);
int insert_at_last(file_list **files, char *filename);
int find_node(file_list *head, char * data);
int Create_database(Hash *h_table, file_list **head);
int Display(Hash *HT);
int Search_Data(Hash *HT,char *str);
int Save_Database(Hash *HT,char *str);
int update_database(Hash *HT,char *str);
int insert_at_first_sub(Main_list *m, char *filename, int wc);
int insert_at_first_main(Hash *HT, int index, char *word, int file_count);
void update_file_list(Hash *ht,file_list **head);
void remove_file(char *data,file_list **head);
#endif