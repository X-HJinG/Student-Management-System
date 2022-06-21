#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varset.h"

void gSM(Dc *p,stu *q)
{
	stu *temp=(stu*)malloc(sizeof(stu));
	temp->GPA=q->GPA;
	strcpy(temp->id,q->id);
	strcpy(temp->name,q->name);
	temp->stuCourse=q->stuCourse;
	p->pstu=temp;
}

void getDataCenter(char *isCno,int mode)
{
	stu *Dhead=NULL,*p1,*p2;
	int flag=0,cnt,mark=0;
	double score1=0,score2=0; 
	free(dc);
	dc=(Dc*)malloc(sizeof(Dc));
	stu *p=head;
	while(p!=NULL)
	{
		for(cnt=0;p->stuCourse[cnt].pcourse!=NULL;cnt++)
		{
			if(strcmp(p->stuCourse[cnt].pcourse->cno,isCno)==0)
			{
				dc->pCs=p->stuCourse[cnt].pcourse;
				gSM(dc,p);
				p1=dc->pstu;
				if(flag==0)	
					p2=Dhead=dc->pstu;
				else
				{
					p2->next=p1;
					p2=p1;
				}
				p1->next=NULL;
				flag++;
				mark++;
			}
		}
		p=p->next;
	}
	p=NULL;
	if(mark!=0)
	{
		for(p1=Dhead;p1!=NULL;p1=p1->next)
		{
			for(cnt=0;;cnt++)
				if(p1->stuCourse[cnt].pcourse==dc->pCs)
				{
					score1=p1->stuCourse[cnt].score;
					break;
				}
			if(mode!=1)
			{
				for(p2=p1;p2!=NULL;p2=p2->next)
				{
					for(cnt=0;;cnt++)
						if(p2->stuCourse[cnt].pcourse==dc->pCs)
						{
							score2=p2->stuCourse[cnt].score;
							break;
						}
					if(score1<score2) 
					{
						swap(p1,p2);
						score1=score2;
					}
				}				
			}																
		}
		if(mode==1)
			printf("共有%d名学生选取该课程\n",flag);
		printf("\n [%s]->%s\n",dc->pCs->cno,dc->pCs->cname);			
		printf("\n 学号\t姓名\t %成绩\n");
		for(dc->pstu=Dhead;dc->pstu!=NULL;dc->pstu=dc->pstu->next)
		{ 
			printf(" %-6s %-7s  ",dc->pstu->id,dc->pstu->name);
			for(cnt=0;;cnt++)
				if(dc->pstu->stuCourse[cnt].pcourse==dc->pCs)
				{
					printf("%-8.2lf\n",dc->pstu->stuCourse[cnt].score);
					break;
				}
		}			
	}
	else printf("\n无课程数据");
	printf("\n\n");
	
}
