#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varset.h"

void changeFILE()
{
	char newFILE_count[100];
	char newFILE_stu[100];
	char newFILE_Cs[100];
	strcpy(newFILE_stu,active_user.name);
	strcat(newFILE_stu,"_stu.txt");
	strcpy(newFILE_Cs,active_user.name);
	strcat(newFILE_Cs,"_Course.txt");
	strcpy(newFILE_count,active_user.name);
	strcat(newFILE_count,"_count.txt");	
		
	if(rename("stu.txt",newFILE_stu)!=EOF)
	{
		rename("Course.txt",newFILE_Cs);
		rename("count.txt",newFILE_count);
	}
		
	else
	{
		rename(newFILE_stu,"stu.txt");
		rename(newFILE_Cs,"Course.txt");
		rename(newFILE_count,"count.txt");
	}
}
