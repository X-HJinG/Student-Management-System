#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varset.h"

Cs* findCourse(char *cno)
{
	int num;
	Cs *course;
	for(num=0;num<8;num++)
	{
		if(strcmp(cno,CourseList[num].cno)==0)
		{
			course=&CourseList[num];
			return course;
		}
	}
}
