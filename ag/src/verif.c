#include <string.h>
#include "verif.h"
#include <stdio.h>
#include <stdlib.h>



int verif( users u )
{	
	char login[30];
	char modp[30];
	int role=0;
      
	int re=0;

	FILE* f = NULL;

	f=fopen("user.txt","r");

while(fscanf(f,"%s %s %d",login,modp,&role)!=EOF)    
{
	if  ((strcmp(login,u.log)==0) && (strcmp(u.pass,modp)==0))
	{
		
		re=role;
	}
	
}

fclose(f);
return(re);
}

