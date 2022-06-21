#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void getCsNum()
{
	stu *p;
	int cnt;
	p=head;
	for(cnt=0;cnt<8;cnt++)
		CourseList[cnt].total=0;
	
	while(p!=NULL)
	{
		for(cnt=0;;cnt++)
		{
			if(p->stuCourse[cnt].pcourse==NULL) break;
			p->stuCourse[cnt].pcourse->total++;
		}
		p=p->next;
	}
} 
