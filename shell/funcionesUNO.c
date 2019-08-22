#include "head.h"

int tamanio(char *linea)
{
        
  char *puntero = linea;
  int contador = 0;
              
  while (puntero[contador])
    {
      contador++;
    }

  return (contador);

}
int env(char **environ, char *linea)
{
	int count = 0;
	char *puntero2 = linea;
	char *exit = "env";
	int i = tamanio(exit);
	int a = 0;

	if (!puntero2)
		return(0);

	while (puntero2[count])

	{

		if (puntero2[count] != exit[count])
			return(0);
		count++;
	}
	if (count == i)
	{

		while(environ[a])
		{
			printf("%s\n", environ[a]);
			a++;
		}

	}
	return (1);
}
int search_env(char **environ, char **arv)
{
	unsigned int i = 0;
	int dos = 0;
	char **pt;
	char *igual = "=";
	char *dospuntos = ":";
	char  buf[100];
	char **token1;
	char **token2;
	char **token3;
	int a = 0; int contad = 1;
	int ojo;
	while(environ[i])
	{
		dos = comparar_env(environ[i]);
		if (dos == 1)
			break;
		i++;
	}
	_strcpy(buf, environ[i]);
	token1 = funciontok(buf, igual);
	token2 = funciontok(token1[1], dospuntos);

	while(token2[a])
	{	
		a++;
		contad++;
	}

        a = 0;
	token3 = concadenar(token2, contad, arv[0]);
	while(token3[a])
	{
	ojo =	execve(token3[a],arv, environ);
	a++;
	}
	return (1);
}          
char **concadenar(char **tokens, int numtokens,char *comando)
{
	char **cajagrande;
	int tam;
	int tam2;
	int num = 0;

	cajagrande = malloc((sizeof (char *)) * (numtokens + 1));
	if (cajagrande == NULL)
		return(NULL);

	while(tokens[num])
	{
		cajagrande[num] = malloc((tamanio(tokens[num]) + 1)+ (tamanio(comando)));
		if (cajagrande == NULL)
			return (NULL);
		concadenar2(cajagrande[num], tokens[num], comando);
		num++;

	}
	return(cajagrande);
}

char *concadenar2(char *dest, char *token, char *comando)
{
	int tam = tamanio(token);
	int tam2 = tamanio(comando);
	int final = tam + tam2 + 1;
	int a = 0;
	int b = 0;
	char *raya = "/";
	while(a <  tam)
	{
		/*if (token[a] == 's' && token[a+1] == 'Q')
		{
			token[a+1] = '\0';
			token[a+2] = '/';
			}*/
		if (token[a] != '\0')
			dest[a] = token[a];
		a++;
	}

	dest[a] = raya[0];
	a++;
	while (a < final)
	{
		dest[a] = comando[b];
		a++;
		b++;
	}
	return (dest);

}
char quitarsalto(char *linea)
{
  
  char *puntero = linea;
  int ta;
  
  ta = tamanio(puntero); 
  puntero[ta - 1] = '\0';

  return(*linea);
}

int comparar_env(char *linea)
{

	int count = 0;
	char *puntero2 = linea;
	char *path = "PATH";
	int pat = tamanio(path);

	while(path[count])
	{
		if(puntero2[count] != path[count])
			return(0);
		count++;
	}
	if (count == pat)
		return(1);
//incluir igual
	return (0);
}
                                  
     
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
                 
int numerotokens(char *linea,char *separador)
{
  char *puntero = linea;
  int cont = 0;
  int cont2 = 1;                      
  while (puntero[cont] != '\0')
    {
      cont++;                   
      if (puntero[cont] == separador[0])
	{
	  cont2++;
      	}
      
    }         
  return (cont2);
}
                              
char **funciontok(char *linea ,char *separador)
{
 
  char **cajagrande;
  char *token; 
  int cont = 0;             
  int tam = numerotokens(linea, separador);
  char strings[_strlen(linea) + 1];
  size_t i, n = _strlen(linea);

  _strcpy(strings, linea);

  cajagrande = malloc((sizeof (char *))* (tam + 1));          
  if (cajagrande == NULL)
    return (NULL);    
  token = strtok(strings, separador);
  while(token != NULL)
    {
                                            
      cajagrande[cont] = malloc(tamanio(token + 1));        
      if (cajagrande == NULL)
	return (NULL);
      _strcpy(cajagrande[cont], token);
      token = strtok(NULL, separador);
      cont++;

    }
    
  
  return(cajagrande);
 
}
