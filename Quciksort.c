#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

//¿ìËÙÅÅÐò
stu* GetPartion(stu *pBegin,stu *pEnd)
{
	double key=pBegin->GPA;
	stu *p=pBegin;
	stu *q=p->next;
	
	while(q!=pEnd)
	{
		if(q->GPA>key)
		{
			p=p->next;
			swap(p,q);	
		}
		q=q->next;
	}
	swap(p,pBegin);
	return p;	
} 

void QuickSort(stu *pBegin,stu *pEnd)
{
	if(pBegin!=pEnd)
	{
		stu *partion=GetPartion(pBegin,pEnd);
		QuickSort(pBegin,partion);
		QuickSort(partion->next,pEnd);
	}
}

