#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"
//����ѧ�� 
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
		printf("��ѧ������\n\n");
		return;
	}
	if(p!=NULL)
	{
		printf("1��ͨ��ѧ�Ų�ѯ\n");
		printf("2��ͨ��������ѯ\n\n");
		printf("������:");
		act=getchar();
//		clearbuffer();
		label:
		switch(act)
		{
			case '1':printf("����ѧ��ѧ��:");
					scanf("%s",n);
					isFound=1;
					break;
			case '2':printf("����ѧ������:");
					scanf("%s",n);
					isFound=2;
					break;
			default:printf("��������,����������:");
					goto label;
		}
		while(p!=NULL)
		{
//			if((isFound=1&&strcmp(p->id,n)==0)||(isFound=2&&strcmp(p->name,n)==0))
			if((isFound=1&&strcmp(p->id,n)==0)||(isFound=2&&strstr(p->name,n)!=NULL))
			{
				if(flag==0) printf("\n ѧ��\t����\t ����\t [�γ̱��]->�ɼ�\n\n");
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
			printf("���޴���\n\n");
			return;
		}
	}
}
