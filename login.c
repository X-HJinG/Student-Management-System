#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "varset.h"
#include <direct.h>


int login()
{
	int i,mark,choose;
	User user;
	char *path=(char*)malloc(sizeof(char)*10000);
	while(1)
	{
		printf("-----||ѧ����Ϣ����ϵͳ||-----\n\n");
		printf("-----�˺�:");
		scanf("%s",user.name);
		printf("-----����:");
		for(i=0;;i++)
		{
			mark=0;
			user.key[i]=getch();
			if(user.key[i]=='\r')
				break;
			if(user.key[0]==8)
			{
				user.key[0]='\0';
				printf("\b:");
				i--;
				mark++;
			}
			if(i>=1)
			{
				if(user.key[i]==8)
				{
					user.key[i-1]='\0';
					printf("\b \b"); 
					i=i-2;
					mark++;
				}	
			}
			if(mark==0)
				printf("*");	
		}
		user.key[i]='\0';
		mark=checkUser(user);
		if(mark==1)
		{
			Sleep(500);
			system("cls");
			printf("\n-----��½�ɹ�\n");
			printf("-----��������");
			for(i=0;i<6;i++)
			{
				printf(".");
				Sleep(150);
			}
			getUser(user);
			setCourse();
			_chdir(user.name);
			changeFILE();
			getData();
			if(head!=NULL)
				printf("\n\n-----�ɹ�����");
			else 
				printf("\n\n-----�޳�ʼ����");
			Sleep(1000);
			system("cls");
			return 1;
		}
		else if(mark==2)
		{
			printf("\n\n-----�˺Ż��������\n");
			Sleep(500);	
		}
		else if(mark==0)
		{
			printf("\n\n-----��ע����Ϣ\n");
		}
		label:
		printf("\n�Ƿ���������(1/0):");
		choose=3;
		scanf("%d",&choose);
		if(choose==1)
		{
			system("cls");
			continue;
		}
		else if(choose==0)
		{
			system("cls");
			return 0;
		}	
		else
		{
			clearbuffer();	
			printf("����������������\n\n");
			goto label;
		} 		
	} 
}
