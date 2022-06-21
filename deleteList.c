#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


int isDeleted()
{
	int choice;
	printf("确定删除（1/0）:");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("删除成功\n\n");
		return 1;
	}
	if(choice==0)
	{
		printf("已取消\n\n");
		return 0;
	}
}

//删除一个学生 
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
		printf("1、通过学号删除\n");
		printf("2、通过姓名删除\n\n");
		printf("请输入:");
		label:
		act=getchar();
		clearbuffer();
		switch(act)
		{
			case '1':printf("\n输入被删除学生学号:");
					scanf("%s",n);
					isFound=1;
					break;
			case '2':printf("\n输入被删除学生姓名:");
					scanf("%s",n);
					isFound=2;
					break;
			default:printf("输入有误,请重新输入:");
					goto label;
		}
		boolean1=(isFound==1)&&(strcmp(p->id,n)==0);
		boolean2=(isFound==2)&&(strcmp(p->name,n)==0);
		if(boolean1||boolean2)
		{
			printf("\n 学号\t姓名\t 绩点\t\n");
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
				printf("\n 学号\t姓名\t 绩点\t\n");
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
		printf("无学生数据\n\n");
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
		printf("查无此人\n\n");
		return;
	}
}
