typedef struct User
{
	char name[20];
	char key[20];
}User;


typedef struct Course
{
	char *cno;
	char *cname;
	int credit;
	int total;
}Cs;

typedef struct StudentCousre
{
	Cs *pcourse;
	double score;
}Sc;


typedef struct Student
{
	char id[20];
	char name[20];
	double GPA;
	struct Student *next;
	Sc *stuCourse; 
}stu;


typedef struct DataCenter
{
	Cs *pCs;
	stu *pstu;
}Dc;

FILE *fp;
FILE *fp_Cs;


Cs CourseList[8];
User active_user;
Dc *dc;
stu *head;

void setDc();
void printList();
void addList(); 
int check(stu *q);
Cs* findCourse(char *cno);
stu* getData();
int getcount();
void menu();
void save();
void change();
void setcount(int cnt);
void sort();
void showCourses();
void getGPA();
void setCourse(); 
