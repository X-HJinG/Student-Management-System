#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

//����
void swap(stu *a,stu *b)
{
	stu temp;
	struct Student *Ptemp;
	temp=*a;
	*a=*b;
	*b=temp;
	Ptemp=a->next;
	a->next=b->next;
	b->next=Ptemp;
}
