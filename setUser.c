#include <stdio.h>
#include <stdlib.h>
#include "varset.h"
#include <direct.h>


void setUser()
{
	User user;
	printf("-----||ѧ����Ϣ����ϵͳ||-----\n\n");
	printf("-----ע���˺�:");
	scanf("%s",user.name);
	printf("\n");
	printf("-----��������:");
	scanf("%s",user.key);
	if((fp=fopen("userfile.txt","a+"))==NULL)
		printf("Can't open the userfile'");
	if(checkUser(user)!=0)
		printf("\n-----���û����ѱ�ע��\n\n");
	
	else if(fprintf(fp,"%s %s\n",user.name,user.key)!=EOF)
	{ 
		_mkdir(user.name); 
		printf("\n-----ע��ɹ�\n\n");
	} 
	fclose(fp);
	system("pause");
	system("cls");
}
