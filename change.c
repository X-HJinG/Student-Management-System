#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


//�ı�ѧ���ɼ� 
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
		printf("��ѧ������\n\n");
		return; 
	} 
	printf("�������޸�ѧ����ѧ��:");
	scanf("%s",id);
	while(p!=NULL)
	{
		setCno=(char*)malloc(sizeof(char)*10);
		if(strcmp(p->id,id)==0)
		{
			printf("\n ѧ��\t����\t  [�γ̱��]->�ɼ�\n\n");
			printf(" %-6s %-8s ",p->id,p->name);
			for(i=0;p->stuCourse[i].pcourse!=NULL;i++)
				printf("[%s]->%.2lf ",p->stuCourse[i].pcourse->cno,p->stuCourse[i].score);
			printf("\n\n");
			printf("�������޸ĵĿγ̱��:");
			scanf("%s",setCno);
			for(cnt=0;p->stuCourse[cnt].pcourse!=NULL;cnt++)
			{
				if(strcmp(p->stuCourse[cnt].pcourse->cno,setCno)==0)
				{
					printf("\n�������޸ĺ�ĳɼ�:");
					scanf("%lf",&p->stuCourse[cnt].score);
					printf("\n�޸ĳɹ�\n");
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
	if(flag==0) printf("���޴���\n");
	getGPA();
	save();
} 
