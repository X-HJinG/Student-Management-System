#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"
//#include <direct.h>

void menu()
{
	int n,choose;
	while(1)
	{
		printf("==================================================\n");
		printf("||	 	��ӭ����ѧ������ϵͳ 		||\n");
		printf("||                                              ||\n");
		printf("||1.���ѧ������		 2��ɾ��ѧ������||\n");
		printf("||3.�����������		 4������ѧ������||\n");
		printf("||5.��ȡѧ������		 6���޸�ѧ���ɼ�||\n");
		printf("||7.��մ�������		 8���˳�ϵͳ    ||\n");
		printf("==================================================\n");		
		printf("�����룺");
		scanf("%d",&n);
		system("cls");
		switch(n)
		{
			case 1:addList();
					break;
			case 2:deleteList();
					break;
			case 3: printData();
					break;
			case 4:search();
					break;
			case 5:sort();
					break;
			case 6:change();
					break;
			case 7:clearList();
					getData();
					break;
			case 8: changeFILE();
					return ;
			default:printf("������������������\n");
					break; 	
		}
		label:
		printf("���ز˵����˳�ϵͳ(1/0):");
		choose=3;
		scanf("%d",&choose);
		if(choose==1)
		{
			system("cls");
			continue;
		}
		else if(choose==0)
		{
			changeFILE();
			break;
		}
		else
		{
			clearbuffer();	
			printf("����������������\n\n");
			goto label;
		}		 
	}	
}
