#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

//获取文件数据 
stu* getData()
{
	stu *p,*p1;
	Cs *saveCs;
	int cnt;
	char *mark;
	head=NULL;
	p1=p;
	int flag=0;
	fp=fopen("stu.txt","r");
	fp_Cs=fopen("Course.txt","r");
//	if((fp=fopen("stu.txt","r"))==NULL)
//		printf("Can't open the file\n");
//	if((fp_Cs=fopen("Course.txt","r"))==NULL)
//		printf("can't open the file");
	while(!feof(fp))
	{
		p=(stu*)malloc(LEN);
		p->stuCourse=(Sc*)malloc(sizeof(Sc)*8);
		if(fscanf(fp,"%s %s %lf\n",p->id,p->name,&p->GPA)==EOF)
		{
			p->stuCourse=NULL;
			p=NULL;
			break;
		}
		for(cnt=0;;cnt++)
		{
			mark=(char*)malloc(sizeof(char));
			fscanf(fp_Cs,"%s ",mark);
			if(strcmp(mark,"end")==0) break;
			saveCs=findCourse(mark);
			p->stuCourse[cnt].pcourse=saveCs;
			fscanf(fp_Cs,"%lf ",&p->stuCourse[cnt].score);
			mark=NULL;
			free(mark);
		}
		p->stuCourse[cnt].pcourse=NULL;
		if(flag==0) head=p;
		else p1->next=p;
		p1=p;
		flag++;
	}
	if(p!=NULL)
		p->next=NULL;
	fclose(fp);
	fclose(fp_Cs);
	return head;
}
