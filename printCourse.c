#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void printCourse()
{
	getCsNum();
	char *isCno=(char*)malloc(sizeof(char)*5);
	int num=0,flag=0;
	char choice;
	if(head==NULL)
	{
		printf("无课程数据\n\n");
		return; 
	}
	showCourses(1);
	label:
	printf("是否查看课程详情(1/0):");
	clearbuffer();
	choice=getchar();
	switch(choice)
	{
		case '1':	printf("请输入课程编号:");
					scanf("%s",isCno);
					system("cls");
					for(num=0;num<8;num++)
					{
						if(strcmp(CourseList[num].cno,isCno)==0)
						{
							flag++;
							break;
						}
					}
					if(flag==0)
					{			
						printf("无此课程信息\n\n");
						return; 
					}
					getDataCenter(isCno,1);
					break;
		case '0':	return;
		default :	printf("输入有误\n\n");
					goto label;
	}

	
}
