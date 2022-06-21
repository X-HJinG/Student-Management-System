#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "varset.h"

int checkUser(User user)
{
	User temp;
	FILE *fp_ck;
	if((fp_ck=fopen("userfile.txt","r"))==NULL)
		return 0;
	while(!feof(fp_ck))
	{
		fscanf(fp_ck,"%s %s\n",temp.name,temp.key);
		if(strcmp(user.name,temp.name)==0&&strcmp(user.key,temp.key)==0)
			return 1;
		if(strcmp(user.name,temp.name)==0&&strcmp(user.key,temp.key)!=0)
			return 2;
	}
	fclose(fp_ck);
	return 0;
		
}
