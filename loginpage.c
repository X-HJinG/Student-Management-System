#include <stdio.h>
#include <string.h>
#include "varset.h"
#include <direct.h>

int loginpage()
{
	int n;
	label:
	printf("************************************\n");
	printf("||     ---学生信息管理系统---     ||\n");
	printf("||                                ||\n");
	printf("||      1、登陆用户               ||\n");
	printf("||      2、注册用户               ||\n");
	printf("||      3、退出                   ||\n");
	printf("************************************\n");
	printf("请输入：");
	scanf("%d",&n);
	system("cls");
	switch(n)
	{
		case 1:if(login())
					break;
				goto label;
		case 2:setUser();
				goto label;
		case 3: return 0;
		default:clearbuffer();
				printf("输入有误，请重新输入\n");
				system("cls");
				goto label; 	
	}
	return 1; 		
}
