#include <stdio.h>
#include <stdlib.h>
#include "varset.h"


extern Dc DataCenter[8];

void setDc()
{
	int i;
	for(i=0;i<8;i++)
	{
		DataCenter[i].pCs=&CourseList[i];
		DataCenter[i].pstu=(stu*)malloc(sizeof(Sc));
	}
}
