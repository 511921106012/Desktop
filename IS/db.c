#include "INDEX.h"

int Create_database(Hash *h_table, file_list **head)
{
    int index;
    file_list *point = *head;
    while(point != NULL)
    {
        FILE *fptr = fopen(point->file_name, "r");
        
        char str[20];
        while(fscanf(fptr, "%s", str) == 1)
        {
            //printf("%s\n",str);
            if (islower((unsigned char)str[0]))
            {
                index = str[0] - 'a';
            }
            else if(isupper((unsigned char)str[0]))
            {
                index = str[0] - 'A';
            }
            else if(isdigit((unsigned char)str[0]))
            {
                index = 26;
            }
            else
            {
                index = 27;
            }

            
            h_table[index].index = index;

            if(h_table[index].next_main == NULL )
            {
                Main_list *new_m = malloc(sizeof(Main_list));
                if (new_m == NULL) { fclose(fptr); return FAILURE; }
                strcpy(new_m->word, str);
                
                new_m->file_count = 1;
                Sub_list *new_s = malloc(sizeof(Sub_list));
                if (new_s == NULL) { free(new_m); fclose(fptr); return FAILURE; }
                new_m->sub_link = new_s;
                new_s->word_count = 1;
                strcpy(new_s->filename, point->file_name);
                
                new_m->main_link = NULL;
                new_s->next_sub = NULL;

                h_table[index].next_main = new_m;
            }
            else
            {
                int found = 0;
                Main_list *main = h_table[index].next_main;
                Main_list *prev_m = NULL;
                while(main != NULL)
                {
                    if(strcmp(main->word, str) == 0)
                    {
                        found = 1;
                        Sub_list *sub_temp = main->sub_link;
                        Sub_list *sub_prev = NULL;
                        while(sub_temp != NULL)
                        {
                            if(strcmp(sub_temp->filename, point->file_name) == 0)
                            {
                                sub_temp->word_count++;
                                break;
                            }
                            sub_prev = sub_temp;
                            sub_temp = sub_temp->next_sub;
                        }
                        if(sub_temp == NULL )
                        {
                            Sub_list *new_sub = malloc(sizeof(Sub_list));
                            if (new_sub == NULL) { fclose(fptr); return FAILURE; }
                            new_sub->word_count = 1;
                            strcpy(new_sub->filename, point->file_name);
                            
                            new_sub->next_sub = NULL;
                            if (sub_prev != NULL)
                                sub_prev->next_sub = new_sub;// add after existing sub list
                            else
                                main->sub_link = new_sub; /*  // first sublist for this main */
                            main->file_count++;
                        }
                        break; /* word found and processed */
                    }
                    prev_m = main;
                    main = main->main_link;
                }
                if(!found)
                {
                    Main_list *new_m = malloc(sizeof(Main_list));
                    if (new_m == NULL) { fclose(fptr); return FAILURE; }
                    strcpy(new_m->word, str);
                    
                    new_m->file_count = 1;
                    Sub_list *new_s = malloc(sizeof(Sub_list));
                    if (new_s == NULL) { free(new_m); fclose(fptr); return FAILURE; }
                    new_m->sub_link = new_s;
                    new_s->word_count = 1;
                    strcpy(new_s->filename, point->file_name);
                    
                    new_m->main_link = NULL;
                    new_s->next_sub = NULL;

                    prev_m->main_link = new_m;
                }
            }
        }

        fclose(fptr);
        point = point->link;
    }

    return SUCCESS;
}

extern int status;
int Display(Hash *ht)
{
    if (status == 0)
    {
        printf("Database is empty first create database!!!\n");
        return FAILURE;
    }

    // Borders and Header
    printf("╔═══════╦═════════════════╦══════════╦═════════════════╦═══════════╗\n");
    printf("║ %-5s ║ %-15s ║ %-8s ║ %-15s ║ %-9s ║\n",
           "Index", "Word", "F-Count", "File Name", "W-Count");
    printf("╠═══════╬═════════════════╬══════════╬═════════════════╬═══════════╣\n");

    int first_block_printed = 0;

    for (int i = 0; i < 28; i++)
    {
        Main_list *mp = ht[i].next_main;

        if (mp == NULL)
            continue; // Skip empty indices

        // Print separator BETWEEN index blocks (but not before the first block)
        if (first_block_printed)
        {
            printf("╠═══════╬═════════════════╬══════════╬═════════════════╬═══════════╣\n");
        }

        first_block_printed = 1;

        while (mp != NULL)
        {
            Sub_list *sp = mp->sub_link;

            // First row
            printf("║ %-5d ║ %-15s ║ %-8d ║ %-15s ║ %-9d ║\n",
                   i, mp->word, mp->file_count, sp->filename, sp->word_count);

            sp = sp->next_sub;

            // Remaining rows
            while (sp != NULL)
            {
                printf("║ %-5s ║ %-15s ║ %-8s ║ %-15s ║ %-9d ║\n",
                       "", "", "", sp->filename, sp->word_count);
                sp = sp->next_sub;
            }

            // Line between words in same index
            if (mp->main_link != NULL)
            {
                printf("╠═══════╬═════════════════╬══════════╬═════════════════╬═══════════╣\n");
            }

            mp = mp->main_link;
        }
    }

    // Bottom border
    printf("╚═══════╩═════════════════╩══════════╩═════════════════╩═══════════╝\n");

    return SUCCESS;
}


int Search_Data(Hash *HT,char *str)
{
    int index=0;
    if (islower((unsigned char)str[0]))
    {
        index = str[0] - 'a';
    }
    else if(isupper((unsigned char)str[0]))
    {
        index = str[0] - 'A';
    }
    else if(isdigit((unsigned char)str[0]))
    {
        index = 26;
    }
    else
    {
        index = 27;
    }
    Main_list *temp=HT[index].next_main;
    while(temp)
    {
        if(strcmp(temp->word,str)==0)
        {
            printf("Index : %d, WORD : %s, File-count : %d",index,temp->word,temp->file_count);
            Sub_list *stemp=temp->sub_link;
            while(stemp)
            {
                printf(", File-name : %s, Word-count : %d",stemp->filename,stemp->word_count);
                stemp=stemp->next_sub;
            }
            return SUCCESS;
        }
        temp=temp->main_link;
    }
    return FAILURE;
}

int Save_Database(Hash *ht,char *str)
{
    FILE *fp=fopen(str,"w");
    if(fp==NULL)
    {
        return FAILURE;
    }
    for (int i = 0; i < 28; i++)
    {

        Main_list *mp = ht[i].next_main;

        while (mp != NULL)
        {
            fprintf(fp,"#");
            Sub_list *sp = mp->sub_link;

            // First row with index + word + fcount
            fprintf(fp,"%d;%s;%d;%s;%d",
                   i, mp->word, mp->file_count, sp->filename, sp->word_count);

            sp = sp->next_sub;

            //  only filename & wcount
            while (sp != NULL)
            {
                fprintf(fp,";%s;%d",sp->filename, sp->word_count);
                sp = sp->next_sub;
            }
            fprintf(fp,"#\n");
            mp = mp->main_link;
        }
    }
    fclose(fp);
    
    return SUCCESS;
}


int update_database(Hash *ht, char *str)
{
    FILE *fp = fopen(str, "r");
    if (!fp)
        return FAILURE;

    int index, file_count;
    char word[50];
    char filename[50];
    int wc;

    while (fscanf(fp, " #%d;%[^;];%d", &index, word, &file_count) == 3)
    {
        insert_at_first_main(ht, index, word, file_count);

        // Now fetch newly inserted node
        Main_list *m = ht[index].next_main;

        for (int i = 0; i < file_count; i++)
        {
            fscanf(fp, ";%[^;];%d", filename, &wc);
            insert_at_first_sub(m, filename, wc);
        }

        fscanf(fp, "#"); // consume ending '#'
    }

    fclose(fp);
    return SUCCESS;
}
