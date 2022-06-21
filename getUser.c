#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varset.h"

extern User active_user;

void getUser(User user)
{
	active_user=user;
	return;
} 
