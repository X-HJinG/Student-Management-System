#include <stdio.h>
#include <string.h>
#include "varset.h"
#include <direct.h>

int loginpage()
{
	int n;
	label:
	printf("************************************\n");
	printf("||     ---ѧ����Ϣ����ϵͳ---     ||\n");
	printf("||                                ||\n");
	printf("||      1����½�û�               ||\n");
	printf("||      2��ע���û�               ||\n");
	printf("||      3���˳�                   ||\n");
	printf("************************************\n");
	printf("�����룺");
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
				printf("������������������\n");
				system("cls");
				goto label; 	
	}
	return 1; 		
}
