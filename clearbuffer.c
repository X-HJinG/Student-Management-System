#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
#include "varset.h"



//«Â¿Ìª∫¥Ê 
int clearbuffer()
{
	int record=0;
	while(getchar()!='\n')
		record++;
	return record;
}
