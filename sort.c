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
		printf("��ѧ������\n\n");
		return; 
	}
	while(1)
	{
		printf("1���鿴��������\n");
		printf("2���鿴ָ���γ�����\n\n");
		label1:
		printf("������:");
		scanf("%d",&choice);
		if(clearbuffer()!=0)
		{
			printf("��������\n");
			goto label1;
		}
		switch(choice)
		{
			case 1:QuickSort(head,NULL);
					printf("\n ѧ��\t����\t ����\t\n");
					for(p=head;p!=NULL;p=p->next)
						printf(" %-6s %-7s  %-8.2lf\n",p->id,p->name,p->GPA);
					printf("\n\n");
					break;
			case 2:printf("������γ̱��:");
					isCno=(char*)malloc(sizeof(char)*5);
					scanf("%s",isCno);
					getDataCenter(isCno,0);
					break;
			default:printf("��������\n");					 
		}
		label2:
		printf("�Ƿ��������(1/0):");
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
			printf("\n��������\n");
			goto label2; 
		}
	}		
}
