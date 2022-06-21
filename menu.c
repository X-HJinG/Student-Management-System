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
		printf("||	 	欢迎进入学生管理系统 		||\n");
		printf("||                                              ||\n");
		printf("||1.添加学生数据		 2、删除学生数据||\n");
		printf("||3.浏览储存数据		 4、查找学生数据||\n");
		printf("||5.获取学生排名		 6、修改学生成绩||\n");
		printf("||7.清空储存数据		 8、退出系统    ||\n");
		printf("==================================================\n");		
		printf("请输入：");
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
			default:printf("输入有误，请重新输入\n");
					break; 	
		}
		label:
		printf("返回菜单或退出系统(1/0):");
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
			printf("输入有误，重新输入\n\n");
			goto label;
		}		 
	}	
}
