#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varset.h"


//²éÖØ 
int check(stu *q)
{
	stu *p=head;
	while(p!=NULL)
	{
		if(strcmp(p->id,q->id)==0)
			return 1;
		p=p->next;
	}
	return 0;
}
