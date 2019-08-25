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
	
		while(linea[cont2] != 32 && linea[cont2])
		{
			cont2++;
			cont3++;
		}
		argumentos[cont] = malloc((sizeof(char) * cont3 + 1));
		if (argumentos == NULL)
		{
			exit(0);
		}
		while(linea[cont5] != 32 && linea[cont5] != '\0')
		{

			argumentos[cont][cont4] = linea[cont5];
			cont5++;
			cont4++;
		}

			argumentos[cont][cont4] = '\0';
		
		if(!linea[cont5])
			break;
		cont++;
		cont2++;
		cont5++;
		cont3 = 0;
		cont4 = 0;

	}
	argumentos[cont+1] = NULL;
}

int numerotokens(char *linea,char *separador)
{
	unsigned int cont = 0;
	unsigned int cont2 = 1;
	while (linea[cont] != '\0')
	{
		cont++;
		if (linea[cont] == separador[0])
		{
			cont2++;
		}

	}
	return (cont2);
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
void _path(char **argumentos, char **environ, int numtokens)
{
	unsigned int path = 0;
	path = search_env(argumentos, environ);
	concadenar(environ[path], argumentos[0]);
}
int concadenar(char *path, char *comando)
{
	char *pathfinal = NULL;
	char **paths = NULL;
	char *separador = ":";
	unsigned int tampath = tamanio(path);
	unsigned int num = numerotokens(path, separador);
	unsigned int a = 0;
	pathfinal = malloc(sizeof(char) * tampath - 4);
	if (pathfinal == NULL)
		return(-1);
	funcionpath(pathfinal, path, tampath);
	paths = malloc(sizeof(char *) * (num + 1));
	if (paths == NULL)
		return(-1);
	separarpath(pathfinal, comando, paths);
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
	_printf("pathfinal -> %s\n", pathfinal);
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


int main(void)
{
	size_t numbytes = 0;
	ssize_t bytesleidos = 0;
	char *linea = NULL;
	char **argumentos = NULL;
	unsigned int a = 0;
	char *separador = " ";       
	unsigned int num = 0;
	unsigned int flag = 0;
	pid_t pid = 0;
	extern char **environ;

/*aqui la del control + c */

	while(1)
	{
		_printf("$ ");
		bytesleidos = getline(&linea, &numbytes, stdin);
		num = numerotokens(linea,separador);
		quitarsalto(linea);
		if(comparar(linea)==1)
		{
			if (flag != 0)
				_free(argumentos, num);
			free(linea);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
		{
			argumentos = malloc(sizeof(char *) * (num + 1));
			guardarargumentos(linea, argumentos);
			funcion(argumentos,num);
			flag++;
/*			execve(argumentos[0], argumentos,environ);
 */
			_path(argumentos,environ, num);
			free(linea);
			_free(argumentos,num);
			exit(0); 
		}
		else 
		{
			wait(NULL);
		}
	}
	free(linea);
	_free(argumentos, num);
	return (0);
}
