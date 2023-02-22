#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DBMS.h"
#include "Functions.h"

void flush(); /// prototype

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int choice;
    char load;
    struct DBMS * head = NULL;

    printf("\n\n--------------------------------Hello! This program lets you manage your Students' Database-----------------------------\n");

    c1:

    printf("\nDo you want to load student database from the file? (y/n): ");

    load = getchar();

    if(load == 'y')
    {
        FILE * fptr = NULL;

        if((fptr = fopen("StudentData.dat", "rb")) == NULL)
        {
            printf("\nCannot open file for loading data!\n\n");
            exit(1);
        }

        loadListFromFile(&head, fptr);

        fclose(fptr);
    }

    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n 1. Print the list.");
        printf("\n 2. Add an item to the list.");
        printf("\n 3. Delete the item from the list.");
        printf("\n 4. Edit an item in the list.");
        printf("\n 5. Search the list by data field.");
        printf("\n 6. Save the list in a file.");
        printf("\n 7. Exit.\n");
        printf("\nYour choice: ");

        scanf("%d",&choice);

        flush();

        switch (choice)
        {

            case  1:  /// Prints the items in the list.
            {
                printList(head);
                break;
            }

            case  2:  /// Adds an item in the list.
            {
                int addChoice;

                printf("\n 1. Insert a new node at the start of the list.");
                printf("\n 2. Insert a new node at the end of the list.");
                printf("\n 3. Insert a new node before a specific node.");
                printf("\n 4. Insert a new node after a specific node.\n");
                printf("\nYour choice: ");
                scanf("%d", &addChoice);

                flush();

                switch (addChoice)
                {
                    case 1:
                    {
                        insertNodeAtStart(&head);
                        printf("\n** The item has been added to the start of the list **\n");
                        break;
                    }

                    case 2:
                    {
                        insertNodeAtEnd(&head);
                        printf("\n** The item has been added to the end of the list **\n");
                        break;
                    }

                    case 3:
                    {
                        insertNodeBefore(head);
                        break;
                    }
                    case 4:
                    {
                        insertNodeAfter(head);
                        break;
                    }

                    break;
                }

                break;
            }

            case  3:  /// Deletes an item from the list.
            {
                int deleteChoice;

                printf("\n 1. Delete an item from the start of the list.");
                printf("\n 2. Delete an item from the end of the list.\n");
                printf("\nYour choice: ");
                scanf("%d", &deleteChoice);

                flush();

                switch (deleteChoice)
                {
                    case 1:
                    {
                        deleteNodeFromStart(&head);
                        printf("\n** The item has been removed from the start of the list **\n\n");
                        break;
                    }

                    case 2:
                    {
                        deleteNodeFromEnd(head);
                        printf("\n** The item has been removed from the end of the list **\n\n");
                        break;
                    }

                    break;
                }

                break;
            }

            case 4:   /// Edits the item in the list
            {
                editData(head);

                break;
            }

            case  5:  /// Search the list for a Data Field
            {
                int idx;
                int f_choice;

                printf("\nEnter a Data Field to search by: \n");
                printf("\n 1. First Name");
                printf("\n 2. Surname");
                printf("\n 3. Intake Year");
                printf("\n 4. Session");
                printf("\n 5. Program");
                printf("\n 6. Roll number\n");
                printf("\nYour choice: ");
                scanf("%d", &f_choice);

                flush();

                idx = searchNodeByData(head, f_choice);

                break;
            }

            case  6:  /// Saves the list in the file.
            {
                FILE * fptr = NULL;
                if((fptr = fopen("StudentData.dat", "wb+")) == NULL)
                {
                    printf("\nCannot open file for saving data!\n\n");
                    break;
                }

                if(saveListToFile(head, fptr) == 0)
                {
                    printf("\nRecord saved successfully\n");
                }

                else
                {
                    printf("\nNot saved in file\n");
                }

                goto c1;

                break;

            }

            case  7:  /// Exits the program.
            {
                printf("\nExiting on user's request.\n\n");
                return(0);
            }

        }

    }

    return 0;

}
































