#include "INDEX.h"

Hash *h_table = NULL;   /* allocate in main, not at file scope */
file_list *head = NULL;
int status=0;int c=0;int u=0;
int main(int argc, char *argv[])
{
    /* allocate hash table: 26 letters + digits + other = 28 buckets */
    h_table = calloc(28, sizeof(Hash));
    if (h_table == NULL)
    {
        fprintf(stderr, "Memory allocation failed for hash table\n");
        return FAILURE;
    }

    if (argc < 2)
    {
        printf("./a.out <filename.txt>...\n");
        printf("Invalid Input!!!⚠️⚠️⚠️\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        int len = strlen(argv[i]);

        if (len >= 4 && strcmp(argv[i] + len - 4, ".txt") == 0)
        {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("%s--- ENTER VALID INPUT ⚠️ ⚠️ ⚠️\nFILE IS NOT IN THE PRESENT DIRECTORY!!!!!\nENTER THE VALID FILENAME\n",argv[i]);
                
                continue;
            }

            fseek(fp, 0, SEEK_END);
            if (ftell(fp) == 0)
            {
                printf("--%s--ENTER VALID INPUT⚠️ ⚠️ ⚠️ \n FILE IS EMPTY!!!!!\nENTER THE VALID FILENAME\n",argv[i]);
                fclose(fp);
                continue;
            }
            rewind(fp);

            if (find_node(head, argv[i]) == SUCCESS)
            {
                printf("%s--- ENTER VALID INPUT⚠️ ⚠️ ⚠️ \nDUPLICATE FILENAME IS NOT ALLOWED!!!\n",argv[i]);
                fclose(fp);
                continue;
            }

            fclose(fp);
            insert_at_last(&head, argv[i]);
        }
        else
        {
            printf("%s--- ENTER VALID EXTENSION .txt ⚠️ ⚠️ ⚠️\n./a.out <filename.txt>...\n",argv[i]);
            printf("Invalid Input!!!\n");
        }
    }
    fflush(stdout);
    int option;
    do{
                
                printf("\n Select your choice among the followings: \n1)Create database \n2)Display database \n3)Search database \n4)Save database\n5)Update database\n6)Exit\n");
                if (scanf("%d",&option) != 1) {
                    /* clear bad input */
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    printf("Invalid input. Try again.\n");
                    
                    continue;
                }

                switch(option)
                {
                    case 1:
                    {
                        if(c!=0)
                        {
                            printf("creating database multiple times!!!\n");
                            continue;
                        }
                        c++;
                        if(u!=0)
                        {
                            update_file_list(h_table,&head);
                        }
                        if (Create_database(h_table, &head) == SUCCESS)
                           { 
                            status=1;
                             printf("Database created successfully.\n");
                            }
                            else
                            printf("Error creating database.\n");
                            break;
                    }
                    case 2:
                    {
                        if(Display(h_table)==SUCCESS)
                        printf("Displaying of the database is successfully completed!!!\n");
                        
                        break;
                    }
                    case 3:
                    {
                        char str[20];
                        printf("Enter the word to search : ");
                        scanf("%s",str);
                        if(Search_Data(h_table,str)==SUCCESS)
                        {
                            printf("\ndata found!!!\n");
                        }
                        else
                            printf("Data not found in the database.\n");
                        break;
                    }
                    case 4:
                    {
                        int flag;
                        do
                        {
                           
                            flag=0;
                            char str[20];
                                printf("Enter the filename to save the database : ");
                                scanf("%s",str);
                                int len=strlen(str);
                                if (len >= 4 && strcmp(str + len - 4, ".txt") == 0)
                                {
                                    FILE *fp=fopen(str,"r");
                                    if(fp==NULL)
                                    {
                                        FILE *fptr = fopen(str,"w");
                                        if(fptr==NULL) 
                                        {
                                            printf("Error creating file!\n");
                                            flag = 1;
                                            continue;
                                        }
                                        if(Save_Database(h_table,str)==SUCCESS)
                                        {
                                            printf("save to database is successfull\n");
                                        }
                                    }
                                    else
                                    {
                                        fseek(fp, 0, SEEK_END);
                                        if (ftell(fp) == 0)
                                        {
                                            fclose(fp);
                                            FILE *fptr = fopen(str,"w");
                                            if(Save_Database(h_table,str)==SUCCESS)
                                            {
                                                printf("save to database is successfull\n");
                                            }
                                        }
                                        else
                                        {
                                            
                                            printf("File is not empty!!!\nDo you want to over write?\n");
                                             start:
                                            printf("1)Yes \n2)Re-enter the new file name\nENETR YOUR CHOICE 1 OR 2:");
                                            int choice;
                                            scanf("%d",&choice);
                                            if(choice==1)
                                            {
                                             
                                                FILE *fptr = fopen(str,"w");
                                                if(fptr==NULL) 
                                                {
                                                    printf("Error creating file!\n");
                                                    flag = 1;
                                                    continue;
                                                }
                                                if(Save_Database(h_table,str)==SUCCESS)
                                                {
                                                    printf("save to database is successfull\n");
                                                }
                                            }
                                            else if(choice==2)
                                            {
                                                flag=1;
                                            }
                                            else
                                            {
                                                printf("INVALID CHOICE ENTER 1 OR 2:\n");
                                                goto start;
                                            }
                                        }
                                    }
                                } 
                                else
                                {
                                    printf("Ivalid filename <filename.txt>\n");
                                    flag=1;
                                }
                        }while(flag);
                        break;
                    }
                   case 5:
                    {
                        if(c!=0)
                        {
                            printf("Updating after create database is not possile\n");
                            continue;
                        }
                        if(u!=0)
                        {
                            printf("Updating database multiple times!!!\n");
                            continue;
                        }
                        status=1;u++;
                        int flag = 0;
                        do
                        {
                            flag = 0;
                            char str[20];
                            printf("Enter the backup filename (.txt): ");
                            scanf("%s", str);

                            int len = strlen(str);
                            if (len < 4 || strcmp(str + len - 4, ".txt") != 0)
                            {
                                printf("Invalid filename extension. Use .txt\n");
                                continue;
                            }

                            FILE *fp = fopen(str, "r");
                            if (fp == NULL)
                            {
                                printf("File does not exist in directory!\n");
                                continue;
                            }

                            // Check if empty file
                            fseek(fp, 0, SEEK_END);
                            if (ftell(fp) == 0)
                            {
                                printf("File is empty!\n");
                                fclose(fp);
                                continue;
                            }

                            rewind(fp);

                            char first = fgetc(fp);
                            char last;
                            long pos = -1;

                            // find last non-whitespace character
                            while (1)
                            {
                                fseek(fp, pos, SEEK_END);
                                last = fgetc(fp);

                                if (last == ' ' || last == '\n' || last == '\r' || last == '\t')
                                {
                                    pos--;
                                    continue;
                                }
                                break;
                            }

                            fclose(fp);

                            if (first == '#' && last == '#')
                            {
                                if (update_database(h_table, str) == SUCCESS)
                                {
                                    printf("Update Database successful\n");
                                    flag = 1;
                                }
                                else
                                {
                                    printf("Error updating database!\n");
                                }
                            }
                            else
                            {
                                printf("Invalid backup format, missing header/footer '#'\n");
                            }

                        } while (!flag);

                        break;
                    }

                    case 6:
                    {
                        free(h_table);
                        return 0;
                    }
                    default:
                    {
                        printf("Invalid choice !!!");
                    }
                }
    }while(option != 6);

}
