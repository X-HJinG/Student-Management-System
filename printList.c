#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


//输出学生列表 
void printList()
{
	stu *p=(stu*)malloc(sizeof(LEN));
	stu *q;
	Sc temp;
	int stuNum=getcount();
	int i,j,flag;
	Cs *pCourse;
	p=head;
	if(p==NULL)
	{
		printf("无学生数据\n\n");
		return;
	}
	printf(" 当前共有 %d 条学生数据\n",stuNum);
	printf("\n 学号\t姓名\t 绩点\t [课程编号]->成绩\n\n");
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p;q!=NULL;q=q->next)
			if(strcmp(p->id,q->id)>0) swap(p,q);												
	}	
	for(p=head;p!=NULL;p=p->next)
	{	
		flag=0;
		printf(" %-6s %-7s  %-8.2lf",p->id,p->name,p->GPA);
		for(i=0;p->stuCourse[i].pcourse!=NULL;i++)
		{
			for(j=i;j>0;j--)
			{
				if(strcmp(p->stuCourse[j].pcourse->cno,p->stuCourse[j-1].pcourse->cno)<0)
				{
					temp=p->stuCourse[j];
					p->stuCourse[j]=p->stuCourse[j-1];
					p->stuCourse[j-1]=temp;
				}
			}
			flag++;
		}
		for(i=0;i<flag;i++)
			printf("[%s]->%.2lf ",p->stuCourse[i].pcourse->cno,p->stuCourse[i].score);
		printf("\n\n");
	}
}
