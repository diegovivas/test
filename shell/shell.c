#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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
  char *env = "env";
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
  

int main(int ac, char ** av)
{
  size_t numbytes;
  ssize_t bytesleidos;
  char *linea;
  int comandos = 0;
  char **tokens;
  
  while (bytesleidos = getline(&linea, &numbytes, stdin))
         
    { 
      quitarsalto(linea);                            comandos = comparar(linea);

      if (comandos == 1)
	return (1);
    
        funciontok(linea);
                            
 }                     
   
  return (0);
}
