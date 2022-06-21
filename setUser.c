#include <stdio.h>
#include <stdlib.h>
#include "varset.h"
#include <direct.h>


void setUser()
{
	User user;
	printf("-----||学生信息管理系统||-----\n\n");
	printf("-----注册账号:");
	scanf("%s",user.name);
	printf("\n");
	printf("-----设置密码:");
	scanf("%s",user.key);
	if((fp=fopen("userfile.txt","a+"))==NULL)
		printf("Can't open the userfile'");
	if(checkUser(user)!=0)
		printf("\n-----该用户名已被注册\n\n");
	
	else if(fprintf(fp,"%s %s\n",user.name,user.key)!=EOF)
	{ 
		_mkdir(user.name); 
		printf("\n-----注册成功\n\n");
	} 
	fclose(fp);
	system("pause");
	system("cls");
}
