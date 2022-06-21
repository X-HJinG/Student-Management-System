#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


int isDeleted()
{
	int choice;
	printf("ȷ��ɾ����1/0��:");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("ɾ���ɹ�\n\n");
		return 1;
	}
	if(choice==0)
	{
		printf("��ȡ��\n\n");
		return 0;
	}
}

//ɾ��һ��ѧ�� 
void deleteList()
{
	stu *p;
	int cnt,isFound=0,flag=0,mark=0,boolean1=0,boolean2=0;
	char n[20];
	int act;
	p=head; 
	clearbuffer();
	if(head!=NULL)
	{
		printf("1��ͨ��ѧ��ɾ��\n");
		printf("2��ͨ������ɾ��\n\n");
		printf("������:");
		label:
		act=getchar();
		clearbuffer();
		switch(act)
		{
			case '1':printf("\n���뱻ɾ��ѧ��ѧ��:");
					scanf("%s",n);
					isFound=1;
					break;
			case '2':printf("\n���뱻ɾ��ѧ������:");
					scanf("%s",n);
					isFound=2;
					break;
			default:printf("��������,����������:");
					goto label;
		}
		boolean1=(isFound==1)&&(strcmp(p->id,n)==0);
		boolean2=(isFound==2)&&(strcmp(p->name,n)==0);
		if(boolean1||boolean2)
		{
			printf("\n ѧ��\t����\t ����\t\n");
			printf(" %-6s %-7s  %-8.2lf\n\n",p->id,p->name,p->GPA);
			flag=1;
			if(isDeleted())
			{
				head=p->next;
				mark=1;
				free(p);
			}		
		}
		while(p->next!=NULL)
		{
			if(flag!=0) break;
			boolean1=(isFound==1)&&(strcmp(p->next->id,n)==0);
			boolean2=(isFound==2)&&(strcmp(p->next->name,n)==0);
			if(boolean1||boolean2)
			{
				printf("\n ѧ��\t����\t ����\t\n");
				printf(" %-6s %-7s  %-8.2lf\n\n",p->next->id,p->next->name,p->next->GPA);
				flag=1;
				if(p->next->next==NULL)
				{
					if(isDeleted())
					{
						p->next=NULL;
						free(p->next);
						mark=1;
						break;					
					}
				}
				else
				{
					if(isDeleted())
					{
						free(p->next);
						p->next=p->next->next;
						mark=1;
						break;						
					}
				}
			}
			p=p->next;
		}					
	}
	else
	{
		printf("��ѧ������\n\n");
		return;
	}
	if(flag==1&&mark==1)
	{
		cnt=getcount()-1;
		setcount(cnt);
		save();
	}
	if(flag==0) 
	{
		printf("���޴���\n\n");
		return;
	}
}
