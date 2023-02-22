struct student
{
    char first_name[20];
    char surname[20];
    int intake_year;
    char session[10];
    char program[10];
    int roll_no;
};

struct DBMS
{
    struct student data;
    struct DBMS * next;
};
