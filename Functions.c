#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DBMS.h"
#include "Functions.h"

void inputStudentData(struct student * stud)
{
    printf("\nEnter the first name of student: ");
    scanf("%s",stud -> first_name);

    printf("\nEnter the surname of the student: ");
    scanf("%s",stud -> surname);

    printf("\nEnter the intake year: ");
    scanf("%d", &(stud -> intake_year));

    printf("\nEnter the session: ");
    scanf("%s",stud -> session);

    printf("\nEnter the program: ");
    scanf("%s",stud -> program);

    printf("\nEnter the roll number of the student: ");
    scanf("%d", &(stud->roll_no));

}

void inputNodeData(struct DBMS * node_x)
{
   inputStudentData(& node_x -> data);
}

void printStudentData(struct student * stud)
{
    printf("\nFirst name:\t %s", stud->first_name);
    printf("\nSurname:\t %s", stud->surname);
    printf("\nIntake year:\t %d", stud->intake_year);
    printf("\nSession:\t %s", stud->session);
    printf("\nProgram:\t %s", stud->program);
    printf("\nRoll No:\t %d\n", stud->roll_no);
}

void printNodeData(struct DBMS * node_x)
{
   printStudentData(& node_x -> data);
}

void printList(struct DBMS * head)
{
    struct DBMS * ptr = head;

    printf("\n*** Start of the list ***\n");

    while(ptr != NULL)
    {
       printNodeData(ptr);
       ptr = ptr -> next;
    }

    printf("\n*** End of the list ***\n\n");
}

bool isListEmpty(struct DBMS * head)
{
    return (head == NULL);
}

int getListLength(struct DBMS * head)
{
    int length = 0;
    struct DBMS * current;

    for(current = head; current != NULL; current = current->next)
    {
      length++;
    }

   return length;
}

int  insertNodeAtStart(struct DBMS ** head)
{
    if(head == NULL)
    {
        *head = (struct DBMS *) malloc(sizeof(struct DBMS));
    }

    struct DBMS * new_node = (struct DBMS *) malloc(sizeof(struct DBMS));

    inputNodeData(new_node);

    new_node -> next= *head;
    *head = new_node;

    return 0;
}

int  insertNodeBefore(struct DBMS * head)
{
    int i = 1;
    int loc;

    struct DBMS * temp, * p;

    temp = (struct DBMS *) malloc(sizeof(struct DBMS));
    inputNodeData(temp);

    printf("\nEnter location: ");
    scanf("%d",&loc);

    int len = getListLength(head);

    printf("\n ** The length of the linked list is %d  **\n", len);

    if (loc > len)
    {
        printf("*** Invalid location ***\n");
    }
    else
    {
        p = head;

        while (i < loc - 1)
        {
            p = p -> next;
            i++;
        }

        temp -> next = p -> next;
        p -> next = temp;
    }

    printf("\n**  The item has been added before the location %d  ** \n", loc);

    return 0;
}

int  insertNodeAfter(struct DBMS * head)
{
    int i = 1;
    int loc;

    struct DBMS * temp, * p;

    temp = (struct DBMS *) malloc(sizeof(struct DBMS));
    inputNodeData(temp);

    printf("\nEnter location\n");
    scanf("%d",&loc);

    int len = getListLength(head);

    printf("\n** The length of the linked list is %d  **\n", len);

    if (loc > len)
    {
        printf("*** Invalid location ***\n");
    }
    else
    {
        p = head;

        while (i < loc)
        {
            p = p -> next;
            i++;
        }

        temp -> next = p -> next;
        p -> next = temp;
    }

    printf("\n** The item has been added after the location %d  **\n", loc);

    return 0;
}

void insertNodeAtEnd(struct DBMS ** head)
{
   struct DBMS * temp = *head;

   struct DBMS * new_node = (struct DBMS*) malloc(sizeof(struct DBMS));

   inputNodeData(new_node);

   new_node -> next = NULL;

   if(isListEmpty(*head))
   {
       *head = new_node;
   }
   else
   {
       while((temp -> next) != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = new_node;
   }

}

void deleteNodeFromStart(struct DBMS ** head)
{
    if(*head == NULL)
    {
        printf("\n*** The list is empty ***\n");
    }
    else
    {

        if((*head) -> next == NULL)
        {
            free(*head);
        }

        else
        {
            *head = (*head) -> next;

        }
    }
}

void deleteNodeFromEnd(struct DBMS * head)
{
    struct DBMS * ptr1 = head, * ptr2;

    while(ptr1 -> next != NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr1 -> next;
    }

    free(ptr2 -> next);
    ptr2 -> next = NULL;
}

void editData(struct DBMS * head)
{
    struct DBMS * temp = head;
    int loc;
    int i = 1;

    printf("\nEnter location: ");
    scanf("%d",&loc);

    int len = getListLength(head);

    printf("\n** The length of the linked list is %d **\n", len);

    if (loc > len)
    {
        printf("*** Invalid location ***\n");
    }

    while((temp -> next != NULL) && (i != loc))
    {
        temp = temp -> next;
        i++;
    }

    inputStudentData(&(temp -> data));
}

int searchNodeByData(struct DBMS * head, int field_num)
{
    int idx = 0;
    switch(field_num)
    {
        case STD_FIRST_NAME:
        {
            printf("\nEnter a first name to search: ");
            char searchName[50];
            scanf("%s",searchName);
            idx = searchDataByFirstName(head, searchName);

            if(idx == -1)
                printf("\nFirst Name searched for is not found!!\n");
            else
                printf("\nThe first name exists at index %d\n", idx);


            break;
        }

        case STD_SURNAME:
        {
            printf("\nEnter a surname to search: ");
            char searchsurname[20];
            scanf("%s",searchsurname);
            idx = searchDataBySurname(head, searchsurname);

            if(idx == -1)
                printf("\nSurname searched for is not found!!\n");
            else
                printf("\nThe surname exists at index %d\n", idx);

            break;
        }

        case STD_INTAKE_YEAR:
        {
            printf("\nEnter intake year to search: ");
            int searchyear = 0;
            scanf("%d", &searchyear);
            idx = searchDataByRoll(head, searchyear);

            if(idx == -1)

                printf("\nIntake year searched for is not found!!\n");

            else

                printf("\nThe intake year exists at index %d\n", idx);

            break;
        }

        case STD_SESSION:
        {
            printf("\nEnter session to search: ");
            char searchsession[10];
            scanf("%s",searchsession);
            idx = searchDataBySession(head, searchsession);

            if(idx == -1)
                printf("\nSession searched for is not found!!\n");
            else
                printf("\nThe session exists at index %d\n", idx);

            break;
        }

        case STD_PROGRAM:
        {
            printf("\nEnter a program to search: ");
            char searchprogram[10];
            scanf("%s",searchprogram);
            idx = searchDataByProgram(head, searchprogram);

            if(idx == -1)
                printf("\nProgram searched for is not found!!\n");
            else
                printf("\nThe program exists at index %d\n", idx);

            break;
        }

        case STD_ROLL_NO:
        {
            printf("\nEnter roll number to search: ");
            int searchroll = 0;
            scanf("%d", &searchroll);
            idx = searchDataByRoll(head, searchroll);

            if(idx == -1)

                printf("\nRoll number searched for is not found!!\n");

            else

                printf("\nThe roll number exists at index %d\n", idx);

            break;
        }

    }
    return(idx);
}

int searchDataByFirstName(struct DBMS * head, char * first_name)
{
    struct DBMS * temp = head;
    int index = 1;

    while((strcmp(temp -> data.first_name, first_name) != 0) && ((temp -> next) != NULL))
    {
        temp = temp -> next;
        index ++;
    }
    if((temp -> next == NULL) && (strcmp(temp -> data.first_name, first_name) != 0))
        return(-1);

    return (index);
}

int searchDataBySurname(struct DBMS * head, char * surname)
{
    struct DBMS * temp = head;
    int index = 1;

    while((strcmp(temp->data.surname,surname) != 0) && ((temp->next) != NULL))
    {
        temp = temp -> next;
        index ++;
    }
    if((temp -> next == NULL) && (strcmp(temp -> data.surname, surname) != 0))
        return(-1);

    return (index);
}

int searchDataByIntake(struct DBMS * head, int intake_year)
{
    struct DBMS * temp = head;
    int index = 1;

    while(((temp -> data.intake_year) != intake_year) && ((temp -> next) != NULL))
    {
        temp = temp->next;
        index ++;
    }

    if((temp -> next == NULL) && ((temp -> data.intake_year) != intake_year))
        return(-1);

    return (index);
}

int searchDataBySession(struct DBMS * head, char * session)
{
    struct DBMS * temp = head;
    int index = 1;

    while((strcmp(temp -> data.session,session) != 0) && ((temp -> next) != NULL))
    {
        temp = temp -> next;
        index ++;
    }

    if((temp -> next == NULL) && (strcmp(temp -> data.session, session) != 0))
        return(-1);

    return (index);
}

int searchDataByProgram(struct DBMS * head, char * program)
{
    struct DBMS * temp = head;
    int index = 1;

    while((strcmp(temp -> data.program, program) != 0) && ((temp -> next) != NULL))
    {
        temp = temp -> next;
        index ++;
    }

    if((temp -> next == NULL) && (strcmp(temp -> data.program, program) != 0))
        return(-1);

    return (index);
}

int searchDataByRoll(struct DBMS * head, int roll_no)
{
    struct DBMS * temp = head;
    int index = 1;

    while(((temp -> data.roll_no) != roll_no) && ((temp -> next) != NULL))
    {
        temp = temp->next;
        index ++;
    }

    if((temp -> next == NULL) && ((temp -> data.roll_no) != roll_no))
        return(-1);

    return (index);
}

int loadListFromFile(struct DBMS ** head, FILE * fptr)
{
    struct student  new_record;

    struct DBMS * temp = *head;

    while(fread(& new_record, sizeof(struct student), 1, fptr) )
    {
        struct DBMS * new_node = (struct DBMS *) malloc(sizeof(struct DBMS));

        new_node->data = new_record;

        new_node->next = NULL;

        if(*head == NULL)
        {
            *head = new_node;
            temp = *head;
        }
        else
        {
            temp -> next = new_node;
            temp = temp -> next;
        }
    }

    return(0);
}

int saveListToFile(struct DBMS * head, FILE * fptr)
{
   struct DBMS * temp = head;

    if(head == NULL)
    {
        return(-1);
    }

    while(temp -> next != NULL)
    {
        fwrite(&(temp -> data), sizeof(struct student), 1,  fptr);
        temp = temp -> next;
    }

    fwrite(&(temp -> data), sizeof(struct student), 1,  fptr);

    return 0;
}













