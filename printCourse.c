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
		printf("�޿γ�����\n\n");
		return; 
	}
	showCourses(1);
	label:
	printf("�Ƿ�鿴�γ�����(1/0):");
	clearbuffer();
	choice=getchar();
	switch(choice)
	{
		case '1':	printf("������γ̱��:");
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
						printf("�޴˿γ���Ϣ\n\n");
						return; 
					}
					getDataCenter(isCno,1);
					break;
		case '0':	return;
		default :	printf("��������\n\n");
					goto label;
	}

	
}
