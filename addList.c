#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

//����ѧ�� 
void addList()
{
	if((fp=fopen("stu.txt","r"))==NULL)
	{
		fp=fopen("stu.txt","w");
	}
	fclose(fp);	
	int cnt,record;
	stu *p,*p1;
	p=head;
	if(p==NULL)
		cnt=0;
	else
	{
		cnt=getcount();
		while(p->next!=NULL&&head!=NULL)
			p=p->next;		
	}
	while(p1=(stu*)malloc(LEN))
	{
		int mark,num,find_cs,i;
		char *setCno; //������ҿγ̱�����ַ��� 
		record=0;
		printf("--------------------\n");
		printf("��%d��ͬѧ\n",cnt+1);
		printf("--------------------\n");
		printf("ѧ��:");
		scanf("%s",p1->id);
		mark=clearbuffer(); 
		if(strcmp(p1->id,"0")==0)
		{
			printf("�������\n\n");
			break;
		}			
		if(check(p1))
		{
			system("cls");
			printf("�����ظ�\n\n");
			continue;
		}		
		printf("����:");
		scanf("%s",p1->name);
		printf("\n�γ���Ϣ\n");
		p1->stuCourse=(Sc*)malloc(sizeof(Sc)*10);
		for(num=0;;num++)
		{
			label:
			printf("�γ̱��:");
			setCno=(char*)malloc(sizeof(char)*20); 			
			scanf("%s",setCno);
			if(num>0)
			{
				for(i=0;i<num;i++)
				{
					if(strcmp(setCno,p1->stuCourse[i].pcourse->cno)==0)
					{
						printf("�γ��ظ�\n");
						printf("----------------\n");
//						printf("����������:");
						goto label;
					}
				}
			}
			if(strcmp(setCno,"help")==0)
			{
				printf("\n");
				showCourses(0);
				goto label;
			}
			if(strcmp(setCno,"0")==0)  
			{
				p1->stuCourse[num].pcourse=NULL;
				break;
			}
			for(find_cs=0;find_cs<8;find_cs++)
			{
				if(strcmp(CourseList[find_cs].cno,setCno)==0)
				{
					p1->stuCourse[num].pcourse=&CourseList[find_cs];
					printf("--|%s|--\n",p1->stuCourse[num].pcourse->cname);
					printf("�ÿγɼ�:");
					scanf("%lf",&p1->stuCourse[num].score);
					break;
				}
				if(find_cs==7)
				{
					printf("�޴˿γ�\n");
					printf("----------------\n");
					goto label;
				} 
			}
			printf("----------------\n");
			setCno=NULL;
			free(setCno);
		}
		p1->stuCourse[num].pcourse=NULL;				
		if(head!=NULL)
			p->next=p1;
		else
			head=p1;
		p=p1;
		p1->next=NULL;
		cnt++;
		printf("--------------------\n\n");
		system("cls");
	}
	setcount(cnt);
	getGPA();
	save();	
}
