#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

//������ 
void setcount(int cnt)
{
	fp=fopen("count.txt","w");
	fprintf(fp,"%d",cnt);
	fclose(fp); 
}
