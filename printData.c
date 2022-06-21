#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void printData()
{
	clearbuffer();
	char choice; 
	printf("1、浏览学生数据\n");
	printf("2、浏览课程数据\n\n");
	printf("请输入:"); 
	choice=getchar();
	system("cls");
	switch(choice)
	{
		case '1':printList();
				break;
		case '2':printCourse();
				break;
		default:printf("输入有误\n\n");
				return; 
	}
}
