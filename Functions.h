#define STD_FIRST_NAME    1
#define STD_SURNAME       2
#define STD_INTAKE_YEAR   3
#define STD_SESSION       4
#define STD_PROGRAM       5
#define STD_ROLL_NO       6

void inputStudentData(struct student * stud);
void inputNodeData(struct DBMS * node_x);

void printStudentData(struct student * stud);
void printNodeData(struct DBMS * node_x);

void printList(struct DBMS * head);

bool isListEmpty(struct DBMS * head);
int getListLength(struct DBMS * head);

int  insertNodeAtStart(struct DBMS ** head);
int  insertNodeBefore(struct DBMS * head);
int  insertNodeAfter(struct DBMS * head);
void  insertNodeAtEnd(struct DBMS ** head);

void deleteNodeFromStart(struct DBMS ** head);
void deleteNodeFromEnd(struct DBMS * head);

void editData(struct DBMS * head);

int searchNodeByData(struct DBMS * head, int field_num);
int searchDataByFirstName(struct DBMS * head, char * first_name);
int searchDataBySurname(struct DBMS * head, char * surname);
int searchDataByIntake(struct DBMS * head, int intake_year);
int searchDataBySession(struct DBMS * head, char * session);
int searchDataByProgram(struct DBMS * head, char * program);
int searchDataByRoll(struct DBMS * head, int roll_no);

int loadListFromFile(struct DBMS ** head, FILE * fptr);
int saveListToFile(struct DBMS * head, FILE * fptr);






