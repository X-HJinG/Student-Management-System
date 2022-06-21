#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void sort()
{
//	QuickSort(head,NULL);
//	printList();
	int choice,cnt;
	char *isCno;
	stu *p;
	if(head==NULL)
	{
		printf("无学生数据\n\n");
		return; 
	}
	while(1)
	{
		printf("1、查看绩点排名\n");
		printf("2、查看指定课程排名\n\n");
		label1:
		printf("请输入:");
		scanf("%d",&choice);
		if(clearbuffer()!=0)
		{
			printf("输入有误\n");
			goto label1;
		}
		switch(choice)
		{
			case 1:QuickSort(head,NULL);
					printf("\n 学号\t姓名\t 绩点\t\n");
					for(p=head;p!=NULL;p=p->next)
						printf(" %-6s %-7s  %-8.2lf\n",p->id,p->name,p->GPA);
					printf("\n\n");
					break;
			case 2:printf("请输入课程编号:");
					isCno=(char*)malloc(sizeof(char)*5);
					scanf("%s",isCno);
					getDataCenter(isCno,0);
					break;
			default:printf("输入有误\n");					 
		}
		label2:
		printf("是否继续操作(1/0):");
		scanf("%d",&choice);
		clearbuffer();
		if(choice==1) 
		{
			system("cls");
			continue;
		};
		if(choice==0)
		{
			printf("\n");
			return;
		}
		if(choice!=1||choice!=0)
		{
			printf("\n输入有误\n");
			goto label2; 
		}
	}		
}
