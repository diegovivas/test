#include "head.h"

char quitarsalto(char *linea)
{

	int ta = tamanio(linea);
	linea[ta - 1] = '\0';

	return(*linea);
}
int tamanio(char *linea)
{

	unsigned int contador = 0;

	while (linea[contador])
	{
		contador++;
	}
	return (contador);

}


void *guardarargumentos(char *linea, char *argumentos[])
{
	unsigned int cont = 0;
	unsigned int cont2 = 0;
	unsigned int cont3 = 1;
	unsigned int cont4 = 0;
	unsigned int cont5 = 0;
	unsigned  int tam = tamanio(linea);

	while (linea[cont])
	{
		while(linea[cont2] == 32)
		{
			cont2++;
		}
	
		while(linea[cont2] != 32 && linea[cont2])
		{
			cont2++;
			cont3++;
		}
		while(linea[cont2] == 32)
		{
			cont2++;
		}
		argumentos[cont] = malloc((sizeof(char) * cont3 + 1));
		if (argumentos == NULL)
		{
			exit(0);
		}
		while(linea[cont5] == 32)
		{
			cont5++;
		}
		while(linea[cont5] != 32 && linea[cont5] != '\0')
		{
			
			argumentos[cont][cont4] = linea[cont5];
			cont5++;
			cont4++;
		}
		argumentos[cont][cont4] = '\0';
		while(linea[cont5] == 32)
		{
			cont5++;
		}		
		if(!linea[cont5])
			break;
		cont++;
		cont3 = 0;
		cont4 = 0;

	}
	argumentos[cont+1] = NULL;
}

int numerotokens(char *linea,char *separador)
{
	unsigned int cont = 0;
	unsigned int cont2 = 1;

	if(!linea[cont])
		return(0);

	while(linea[cont] == separador[0])
	{
		cont++;
		if(linea[cont] == '\0')
			return(0);
	}
	while (linea[cont] != '\0')
	{
		if(linea[cont] == separador[0] && linea[cont + 1] == '\0')
			cont2--;
		if (linea[cont] == separador[0] && linea[cont + 1] != separador[0])
			cont2++; 
		cont++;
	}
	return (cont2);
}

void _path(char **argumentos, char **environ, int numtokens, int cont)
{
	unsigned int path = 0;

	if(comparar_envi(argumentos[0]) == 0)
	{
		path = search_env(argumentos, environ);
		concadenar(environ[path], argumentos, environ, cont);
	}
}
int comparar_envi(char *comando)
{

        unsigned int count = 0;
        char *path = "/bin";
        unsigned int pat = tamanio(path);

        while(path[count])
        {
                if(comando[count] != path[count])
                        return(0);
                count++;
        }
        if (count == pat)
                return(1);
        return (0);
}
int concadenar(char *path, char **comando, char **environ, int cont)
{
	char *pathfinal = NULL;
	char **paths = NULL;
	char *separador = ":";
	unsigned int tampath = tamanio(path);
	unsigned int num = numerotokens(path, separador);
	unsigned int i = 0;
	unsigned int a = 0;
	struct stat ojo;

	pathfinal = malloc(sizeof(char) * tampath - 4);
	if (pathfinal == NULL)
		return(-1);
	funcionpath(pathfinal, path, tampath);
	paths = malloc(sizeof(char *) * (num + 1));
	if (paths == NULL)
		return(-1);
	for (i = 0; i < (num + 1); ++i)
		paths[i] = NULL;
	separarpath(pathfinal, comando[0], paths);
	while(paths[a])
	{
		if (stat(paths[a], &ojo) == 0)
			execve(paths[a], comando, environ);
		a++;
	}
	_printf("sh: %d: %s: not found\n", cont, comando[0]);
	_free(paths, a);
	free(pathfinal);
	exit(0);
}
int separarpath(char *pathfinal, char *comando, char **paths)
{
	unsigned int a = 0;
	
	guardarargumentos2(pathfinal, paths, comando);

}
int guardarargumentos2(char *linea, char *argumentos[], char *comando)
{
        unsigned int cont = 0;
        unsigned int cont2 = 0;
        unsigned int cont3 = 1;
        unsigned int cont4 = 0;
        unsigned int cont5 = 0;
	unsigned int cont6 = 0;
        unsigned  int tam = tamanio(comando);


        while (linea[cont])
        {

                while(linea[cont2] != 58 && linea[cont2])
                {
                        cont2++;
                        cont3++;
                }
                argumentos[cont] = malloc((sizeof(char) * (cont3 + tam + 2)));
		if (argumentos == NULL)
                {
                        exit(0);
                }
                while(linea[cont5] != 58 && linea[cont5] != '\0')
                {

                        argumentos[cont][cont4] = linea[cont5];
                        cont5++;
                        cont4++;
                }
		argumentos[cont][cont4] = '/';
		cont4++;
		while(comando[cont6])
		{
			argumentos[cont][cont4] = comando[cont6];
			cont4++;
			cont6++;
		}	  

			argumentos[cont][cont4] = '\0';

                if(!linea[cont5])
                        break;
                cont++;
                cont2++;
                cont5++;
                cont3 = 0;
                cont4 = 0;
		cont6 = 0;

        }
        argumentos[cont+1] = NULL;
}
/*
int limpiar(char *linea)
{
        int a = 0;
        if (linea == NULL)
                return(0);
        while(linea[a])
        {

                linea[a] = '\0';
                a++;

        }
        return (1);
}
int limpiar2(char *linea)
{
	int a = 0;
	if (linea == NULL)
		return (0);
	while(linea[a] != '\n')
	{
		a++;
	}
	while(linea[a])
	{
		linea[a] = '\0';
		a++;

	}
	return (1);

}

int _getline(char *linea)
{
        int a = 0;
        int flag = 0;
        static char buffer[1024];
        limpiar(linea);
	if (read(STDIN_FILENO, buffer, 1024) == EOF)
		return(0);
        while(buffer[a])
        {
                a++;
        }
        while(flag < a)
        {

                linea[flag] = buffer[flag];
                flag++;
        }
	limpiar2(linea);
        limpiar(buffer);
        return(a);

}
*/
int funcionpath(char *pathfinal, char *path, int tam)
{
	unsigned int cont = 0;
	unsigned int igual = 6;
	while(igual < tam)
	{
		pathfinal[cont] = path[igual];
		igual++;
		cont++;
	}
}
int search_env(char **argumentos, char **environ)
{
	unsigned int cont = 0;

	while(environ[cont])
	{
		if(comparar_env(environ[cont]) == 1)
		{
			break;
		}
		cont++;
	}
	return(cont);

}
int comparar_env(char *comando)
{

        unsigned int count = 0;
        char *path = "PATH=";
        unsigned int pat = tamanio(path);

        while(path[count])
        {
                if(comando[count] != path[count])
                        return(0);
                count++;
        }
        if (count == pat)
                return(1);
        return (0);
}
void funcion(char **arg,int num)
{
        unsigned int a = 0;
        while(a < num)
        {
                _printf("%s\n", arg[a]);
                a++;
        }
}


int main(void)
{
	size_t numbytes = 0;
	ssize_t bytesleidos = 0;

	char *linea = NULL;

	//char linea[1024]; sin getline
	char **argumentos = NULL;
	unsigned int a = 0;
	char *separador = " ";       
	unsigned int num = 0;
	unsigned int flag = 0;
	pid_t pid = 0;
	extern char **environ;
	int ojo = 0;
	int cont = 1;
	int status;
	int gh = 0;
/*aqui la del control + c */

	while(1)
	{
		if (pid == -1)
		{
			perror("Error:");
			exit(0);
		}
		if (isatty(STDIN_FILENO))
			_printf("$ ");

/*		if ((gh = _getline(linea)) == EOF)
				exit(0);
*/ // sin getline.

		if((bytesleidos = getline(&linea, &numbytes, stdin) == EOF))
		{

			exit(0);
		}

		quitarsalto(linea);
		num = numerotokens(linea,separador);
		if(comparar(linea) == 1)
		{
			if (flag != 0)
				_free(argumentos, num);
			free(linea);
			exit(0);
		}
		if (num != 0)
		{
			pid = fork();
			if (pid == 0)
			{
				argumentos = malloc(sizeof(char *) * (num + 1));
				if(argumentos == NULL)
				{
					exit(0);
				}
				guardarargumentos(linea, argumentos);
				flag++;
				_path(argumentos,environ, num, cont);
				ojo = execve(argumentos[0], argumentos,environ);
				if (ojo == -1)
					_printf("sh: %d: %s: not found\n", cont, argumentos[0]);
				free(linea);
				_free(argumentos,num);
				exit(0); 
			}
			else 
			{
				wait(NULL);
			}
		}
		cont++;

	}
	free(linea);
	_free(argumentos, num);
	return (0);
}
