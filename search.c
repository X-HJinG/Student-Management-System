#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"
//查找学生 
void search()
{
	stu *p;
	int isFound=0,flag=0,i;
	char n[20];
	int act;
	p=head; 
	clearbuffer();
	if(p==NULL)
	{
		printf("无学生数据\n\n");
		return;
	}
	if(p!=NULL)
	{
		printf("1、通过学号查询\n");
		printf("2、通过姓名查询\n\n");
		printf("请输入:");
		act=getchar();
//		clearbuffer();
		label:
		switch(act)
		{
			case '1':printf("输入学生学号:");
					scanf("%s",n);
					isFound=1;
					break;
			case '2':printf("输入学生姓名:");
					scanf("%s",n);
					isFound=2;
					break;
			default:printf("输入有误,请重新输入:");
					goto label;
		}
		while(p!=NULL)
		{
//			if((isFound=1&&strcmp(p->id,n)==0)||(isFound=2&&strcmp(p->name,n)==0))
			if((isFound=1&&strcmp(p->id,n)==0)||(isFound=2&&strstr(p->name,n)!=NULL))
			{
				if(flag==0) printf("\n 学号\t姓名\t 绩点\t [课程编号]->成绩\n\n");
				printf(" %-6s %-7s  %-8.2lf",p->id,p->name,p->GPA);
				for(i=0;p->stuCourse[i].pcourse!=NULL;i++)
					printf("[%s]->%.2lf ",p->stuCourse[i].pcourse->cno,p->stuCourse[i].score);
				printf("\n\n");
				flag++;			
			}
			p=p->next;
		}
		
		if(flag==0) 
		{
			printf("查无此人\n\n");
			return;
		}
	}
}
