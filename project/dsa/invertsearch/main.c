#include<stdio.h>
int main()
{
    int choice;
    do 
    {
        printf("Select your choice among following options : ")
        printf(" 1 create data base\n");
        printf(" 2 search data base\n");
        printf(" 3 dispaly  the data base\n");
        printf(" 4 update data base\n");
        printf(" 5 exit\n\n");

        printf("enter the your choice 😊 : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            create_database();
            break;
            case 2:
            search_database();
            break;
            dispaly_database();
            case 3:
            save_database();
            break;
            case 4:
            update_database();
            break;
            case 5:
            exit_database();
            break;
        }

    }while(choice!=5);
    
}