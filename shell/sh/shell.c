#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

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
                 
char quitarsalto(char *linea)
{
  
  char *puntero = linea;
  int ta;
  
  ta = tamanio(puntero); 
  puntero[ta - 1] = '\0';

  return(*linea);
}
                                       
int comparar(char *linea)
{
                               
  int count = 0;       
  char *puntero2 = linea;
  char *exit = "exit";
  int i = tamanio(exit);       
  while (puntero2[count])
                                  
    {
                                        
      if (puntero2[count] != exit[count])
	  return(0);
            
	  count++;
    }
  if (count != i)
    return (0);
  
  return (1);
}
                 
int numerotokens(char *linea)
{
  char *puntero = linea;
  int cont = 0;
  int cont2 = 1;
  char *separador = " ";                               
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
                              
char **funciontok(char *linea)
{
 
  char **cajagrande;
  char *token; 
  int cont = 0;             
  int tam = numerotokens(linea);
  char strings[tam + 1];
                  
  strcpy(strings, linea);
  
  cajagrande = malloc((sizeof (char *))* (tam + 1));          
  if (cajagrande == NULL)
    return (NULL);    
  token = strtok(strings, " ");
  while(token != NULL)
    {
                                            
      cajagrande[cont] = malloc(tamanio(token + 1));        
      if (cajagrande == NULL)
	return (NULL);
      strcpy(cajagrande[cont], token);
      token = strtok(NULL, " ");
      cont++;

    }
    
  
  return(cajagrande);
 
}
  
                                                       
int main(int ac, char **av,char **env)
{
   size_t numbytes;
  ssize_t bytesleidos;
  char *linea;
  int comandos = 0;
  char **tokens;  
  char *linea2;
  pid_t proceso;
  int a;            
  printf("-->$ ");
  while (bytesleidos = getline(&linea, &numbytes, stdin))
         
    {
      linea2 = linea;
      if (quitarsalto(linea))
	{
	  tokens = funciontok(linea2);
	  comandos = comparar(tokens[0]);
                                                                        
	  if (comandos == 1)
	    _Exit(99);

                  
	  proceso = fork();
	  if (proceso == 0)
                         
	    {      
                                          
 	      a = execve(tokens[0], tokens, env);
	      if (a == -1)    
		      printf("sh: %d: %s: not found\n", comandos, tokens[0]);                 exit(0);      
	    }
	  else
	  {
		  wait(NULL);
                      
	  }
	}

      printf("-->$ ");
    }                      
   
  return (0);
}
