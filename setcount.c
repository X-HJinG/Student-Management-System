#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"

//¼ÆÊýÆ÷ 
void setcount(int cnt)
{
	fp=fopen("count.txt","w");
	fprintf(fp,"%d",cnt);
	fclose(fp); 
}
