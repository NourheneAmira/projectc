#include <string.h>
#include "verif.h"
#include <stdio.h>
#include <stdlib.h>



int verif( char identifiant[],char password[])
{	
	char login[30];
	char modp[30];
	int role=0;
      
	int re=0;

	FILE* f = NULL;

	f=fopen("user.txt","r");

while(fscanf(f,"%s %s %d",login,modp,&role)!=EOF)    
{
	if  ((strcmp(login,identifiant)==0) && (strcmp(password,modp)==0))
	{
		
		re=role;
	}
	
}

fclose(f);
return(re);
}

