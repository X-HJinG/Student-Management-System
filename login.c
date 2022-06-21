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
		printf("-----||学生信息管理系统||-----\n\n");
		printf("-----账号:");
		scanf("%s",user.name);
		printf("-----密码:");
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
			printf("\n-----登陆成功\n");
			printf("-----加载数据");
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
				printf("\n\n-----成功加载");
			else 
				printf("\n\n-----无初始数据");
			Sleep(1000);
			system("cls");
			return 1;
		}
		else if(mark==2)
		{
			printf("\n\n-----账号或密码错误\n");
			Sleep(500);	
		}
		else if(mark==0)
		{
			printf("\n\n-----无注册信息\n");
		}
		label:
		printf("\n是否重新输入(1/0):");
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
			printf("输入有误，重新输入\n\n");
			goto label;
		} 		
	} 
}
