#include "head.h"

int _free(char **token)
{
	int a = 0;

	while(token[a])
	{

		free(token[a]);
		a++;
	}
	free(token);

	return(1);
}
