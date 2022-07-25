/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:54:33 by scaiazzo          #+#    #+#             */
/*   Updated: 2022/07/24 19:55:21 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int check_input(int **input, int n);
void assegnazioni_sicure(int **input, int **mat, int n);
int autocompletamento(int **input, int **mat, int n);
int crescenza(int **input, int **mat, int n);
void brute(int **mat, int **sure, int n, int error);

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int n;
	char out;
	int **mat = malloc(4*8);    
	int **input = malloc(4*8);
	int **sure = malloc(4*8);
    
	mat[0]=malloc(4*4);
	mat[1]=malloc(4*4);
	mat[2]=malloc(4*4);
	mat[3]=malloc(4*4);
	input[0]=malloc(4*4);
	input[1]=malloc(4*4);
	input[2]=malloc(4*4);
	input[3]=malloc(4*4);
	sure[0]=malloc(4*4);
	sure[1]=malloc(4*4);
	sure[2]=malloc(4*4);
	sure[3]=malloc(4*4);

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
        if(i%2 && argv[1][i] != 32)//posizioni dispari deve avere spazio
        {
            return (0);
        }
        else if(!(i%2) && (argv[1][i] < 49 || argv[1][i] > (n + 48)))//posizione pari deve avere un numero e validità numero
        {
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
        return (0);
    }
    assegnazioni_sicure(input, mat, n);
    while(autocompletamento(input, mat, n) || crescenza(input, mat, n))
    {
    }
     i = 0;
    while(i < n)
    {
    	j = 0;
    	while(j < n)
    	{
    		if(mat[i][j])
    			sure[i][j] = 1;
    		j++;
    	}
    	i++;
    }
    brute(mat, sure, n, 0);
    //autocompletamento(input, mat, n);
    i = 0;
    while(i < n)
    {
    	j = 0;
    	while(j < n)
    	{
    		out = mat[i][j]+48;
    		write(1, &out, 1);
    		if(j != n-1)
    			write(1, " ", 1);
    		j++;
    	}
    	write(1, "\n", 1);
    	i++;
    }
}
