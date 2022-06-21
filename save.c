#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


//储存数据 
void save()
{
	stu *p;
	Cs *pCourse;
	int flag=0,cnt,i,j;
	p=head;
	if((fp=fopen("stu.txt","w"))==NULL)
		printf("can't open the file");
	if((fp_Cs=fopen("Course.txt","w"))==NULL)
		printf("can't open the file");
	if(p==NULL)
	{
		fclose(fp);
		fclose(fp_Cs);
		return;
	}
	while(p!=NULL)
	{
		//存储课程编号 
		for(cnt=0;cnt<=8;cnt++)
		{
			if(p->stuCourse[cnt].pcourse==NULL) break;
			fprintf(fp_Cs,"%s %.1lf ",p->stuCourse[cnt].pcourse->cno,p->stuCourse[cnt].score);
		}
		fprintf(fp_Cs,"end\n");
		
		 
		//存储学生身份信息 
		fprintf(fp,"%s %s %lf\n",p->id,p->name,p->GPA);
		p=p->next;
	}
	fclose(fp_Cs);
	fclose(fp);
} 
