#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

void printData()
{
	clearbuffer();
	char choice; 
	printf("1�����ѧ������\n");
	printf("2������γ�����\n\n");
	printf("������:"); 
	choice=getchar();
	system("cls");
	switch(choice)
	{
		case '1':printList();
				break;
		case '2':printCourse();
				break;
		default:printf("��������\n\n");
				return; 
	}
}
