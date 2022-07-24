int check_input(int **input, int n);
void assegnazioni_sicure(int **input, int **mat, int n);
int autocompletamento(int **input, int **mat, int n);
int crescenza(int **input, int **mat, int n);
void brute(int **mat, int **sure, int n, int error);
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int i=0;
    int j;
    int k;
    int n;
    int **mat = malloc(4*8);    
    int **input = malloc(4*8);
    int **sure = malloc(4*8);
	mat[0]=malloc(sizeof(int)*4);
	mat[1]=malloc(sizeof(int)*4);
	mat[2]=malloc(sizeof(int)*4);
	mat[3]=malloc(sizeof(int)*4);
	input[0]=malloc(sizeof(int)*4);
	input[1]=malloc(sizeof(int)*4);
	input[2]=malloc(sizeof(int)*4);
	input[3]=malloc(sizeof(int)*4);
	sure[0]=malloc(sizeof(int)*4);
	sure[1]=malloc(sizeof(int)*4);
	sure[2]=malloc(sizeof(int)*4);
	sure[3]=malloc(sizeof(int)*4);

//"3 4 1 2 2 1 2 2 2 2 1 2 2 1 4 3";
//3 2 1 4
//2 2 2 1
//3 2 1 4
//2 2 2 1

    n = 0;
    i = 0;
    if(argc != 2) //Check se il numero di argomenti è diverso da 1
        return (0);
    while(argv[1][i]) //Misura la lunghezza della stringa
    {
        if(i%2 == 0)
            n++;
        i++;
    }
    if(n%4)//# numeri non divisibili per 4
        return(0);
    n /= 4; // n = lunghezza del lato, 4 è il numero di lati
    if(n < 4) //se il lato è minore di 4 errore
        return (0);
    i = 0;
    while(argv[1][i])//controllo formattazione input
    {
        if(i%2 && argv[1][i] != 32)//posizioni pari deve avere spazio
        {
            printf("stai uscendo perchè lo spazio\n");
            return (0);
        }
        else if(!(i%2) && (argv[1][i] < 49 || argv[1][i] > (n + 48)))//posizione dispari deve avere un numero e validità numero
        {
            printf("uscita per invalidità numerica\nboia");
            return (0);
        }
        i++;
    }
    i = 0;
    k = 0;
    while(i < 4)//estrazione dati
    {
        j = 0;
        while(j < n)
        {
            input[i][j] = argv[1][k] - 48;
            j++;
            k+=2;
        }
        i++;
    }
    if(check_input(input, n))
    {
    	printf("input invalido\n");
        return (0);
    }
    assegnazioni_sicure(input, mat, n);
    i=0;
    while(i<4){
        j=0;
        while(j<4)
        {
            printf("%d  ", mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
        printf("\n");
    printf("autocompletamento\n");
    while(autocompletamento(input, mat, n) || crescenza(input, mat, n))
    {
  	  i=0;
  	  while(i<4)
  	  {
   	     j=0;
   	     while(j<4)
    	    {
 	           printf("%d  ", mat[i][j]);
  	          j++;
  	      }
  	      printf("\n");
  	      i++;
  	  }
       	 printf("\n");
    }
    i = 0;
    while(i < n)
    {
    	
    	j=0;
    	while(j < n)
    	{
    		if(mat[i][j] != 0)
    			sure[i][j] = 1;
    		else
    			sure[i][j] = 0;
    		j++;
    	}
    	i++;
    }
    brute(mat, sure, n, 0);
    
    i=0;
    while(i<4){
        j=0;
        while(j<4)
        {
            printf("%d  ", mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
        printf("\n");
}
