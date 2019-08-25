#include "head.h"

int comparar(char *linea)
{

	int count = 0;
	char *puntero2 = linea;
	char *exit = "exit";
	int i = tamanio(exit);

	if (!puntero2)
		return(0);

	while (puntero2[count])

	{

		if (puntero2[count] != exit[count])
			return(0);

		count++;
	}
	if (count == i)
		return (1);

	return (0);
}
