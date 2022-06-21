#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void showCourses(int mode)
{
	char cno[20]={"���"};
	char cname[20]={"�γ�����"};
	char credit[20]={"ѧ��"};
	char total[20]={"ѡ������"};
	int num;
	printf(" -----------------------------\n");
	if(mode==0)
		printf("|%-4s|%-15s|%-8s|\n",cno,cname,credit);
	if(mode==1)
		printf("|%-4s|%-15s|%-8s|\n",cno,cname,total);
	printf(" -----------------------------\n");
	for(num=0;num<8;num++)
	{
		if(mode==0)
			printf("|%-4s|%-15s|%-8d|\n",CourseList[num].cno,CourseList[num].cname,CourseList[num].credit);
		if(mode==1)
			printf("|%-4s|%-15s|%-8d|\n",CourseList[num].cno,CourseList[num].cname,CourseList[num].total);
		printf(" -----------------------------\n");
	}
	printf("\n\n");
}
