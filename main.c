int check_input(int **input, int n);
void assegnazioni_sicure(int **input, int **mat, int n);
void autocompletamento(int **mat, int n);
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int i=0;
    int j;
    int k;
    int n;
    int *a = malloc(4*4);
    int *b = malloc(4*4);
    int *c = malloc(4*4);
    int *d = malloc(4*4);
    int **mat = malloc(4*8);    
    int **input = malloc(4*8);
    j=0;
	while(j<4){
		a[j]=0;
		b[j]=0;
		c[j]=0;
		d[j]=0;
		j++;
	}
	mat[0]=a;
	mat[1]=b;
	mat[2]=c;
	mat[3]=d;
	a=malloc(4*4);
	b=malloc(4*4);
	c=malloc(4*4);
	d=malloc(4*4);
	input[0]=a;
	input[1]=b;
	input[2]=c;
	input[3]=d;

//3 2 1 4
//2 2 2 1
//3 2 1 4
//2 2 2 1
//"3 4 1 2 2 1 2 2 2 2 1 2 2 1 4 3";
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
    printf("autocompletamento inizia da qui, finalmente\n");
    autocompletamento(mat, n);
	
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
}
