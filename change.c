#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


//改变学生成绩 
void change()
{
	stu *p;
	int flag=0,cnt,i;
	double score;
	char *setCno;
	char id[20];
	p=head;
	if(head==NULL)
	{
		printf("无学生数据\n\n");
		return; 
	} 
	printf("请输入修改学生的学号:");
	scanf("%s",id);
	while(p!=NULL)
	{
		setCno=(char*)malloc(sizeof(char)*10);
		if(strcmp(p->id,id)==0)
		{
			printf("\n 学号\t姓名\t  [课程编号]->成绩\n\n");
			printf(" %-6s %-8s ",p->id,p->name);
			for(i=0;p->stuCourse[i].pcourse!=NULL;i++)
				printf("[%s]->%.2lf ",p->stuCourse[i].pcourse->cno,p->stuCourse[i].score);
			printf("\n\n");
			printf("请输入修改的课程编号:");
			scanf("%s",setCno);
			for(cnt=0;p->stuCourse[cnt].pcourse!=NULL;cnt++)
			{
				if(strcmp(p->stuCourse[cnt].pcourse->cno,setCno)==0)
				{
					printf("\n请输入修改后的成绩:");
					scanf("%lf",&p->stuCourse[cnt].score);
					printf("\n修改成功\n");
					break;
				}
			}
			flag=1;
			break;
		}
		free(setCno);
		setCno=NULL;
		p=p->next;
	}
	if(flag==0) printf("查无此人\n");
	getGPA();
	save();
} 
