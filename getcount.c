#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"
//��ȡ������ 
int getcount()
{
	int cnt=1;
	fp=fopen("count.txt","r");
	fscanf(fp,"%d",&cnt);
	fclose(fp); 
	return cnt;
} 
