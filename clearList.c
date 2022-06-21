#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"


//初始化
void clearList()
{
	int mark=0;
	if((fp=fopen("stu.txt","w"))==NULL)
	{
		printf("can't open the file1");
		mark++;
	}	
	if((fp_Cs=fopen("Course.txt","w"))==NULL)
	{
		printf("can't open the file2");
		mark++;
	}
	if(mark!=0)	printf("清空失败\n\n");
	else printf("清空成功\n\n"); 
	
	fclose(fp);
	fclose(fp_Cs);		
}
