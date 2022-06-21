#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void getGPA()
{
	stu*p;
	p=head;
	int sum,total_credit,num;
	double score=0;
	while(p!=NULL)
	{
		sum=0;
		total_credit=0;
		for(num=0;;num++)
		{
			if(p->stuCourse[num].pcourse==NULL) break;
			if(p->stuCourse[num].score>=60)
				sum+=p->stuCourse[num].score*p->stuCourse[num].pcourse->credit;	
			total_credit+=p->stuCourse[num].pcourse->credit;
		}
		if(sum==0) total_credit=1;
		score=sum/(10.0*total_credit);
		p->GPA=score;	
		p=p->next;
	}
} 
