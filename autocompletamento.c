/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletamento.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:55:38 by scaiazzo          #+#    #+#             */
/*   Updated: 2022/07/24 19:55:45 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	autocompletamento_riga(int **mat, int n)
{
	int	i;
	int	j;
	int	count;
	int	pos;
	int	numbers[4];

	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			numbers[j] = j+1;
			j++;
		}
		count = 0;
		j = 0;
		while(j < n)
		{
			if(mat[i][j] != 0)
				numbers[mat[i][j]-1] = 0;
			else
			{
				pos = j;
				count++;
			}
			j++;
		}
		if(count == 1)
		{
			j = 0;
			while(j < n)
			{
				if(numbers[j]!=0)
				{
					mat[i][pos] = numbers[j];
					break;
				}
				j++;
			}
			return (1);
		}
			
		i++;
	}
	return (0);
}

int	autocompletamento_colonna(int **mat, int n)
{
	int	i;
	int	j;
	int	count;
	int	pos;
	int	numbers[4];

	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			numbers[j] = j+1;
			j++;
		}
		count = 0;
		j = 0;
		while(j < n)
		{
			if(mat[j][i] != 0)
				numbers[mat[j][i]-1] = 0;
			else
			{
				pos = j;
				count++;
			}
			j++;
		}
		if(count == 1)
		{
			j = 0;
			while(j < n)
			{
				if(numbers[j]!=0)
				{
					mat[pos][i] = numbers[j];
					break;
				}
				j++;
			}
			return (1);
		}
			
		i++;
	}
	return (0);
}

int	autocompletamento_sparsi(int **mat, int n)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	count;
	int	numbers[4][4];

	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			k = 0;
			while(k < n)
			{
				numbers[j][k] = 0;
				k++;
			}
			j++;
		}
		j = 0;
		count = 0;
		while(j < n)
		{
			k = 0;
			while(k < n)
			{
				if(mat[j][k] == i+1)
				{
					l = 0;
					while(l < n)
					{
						numbers[l][k] = i+1;
						l++;
					}
					l = 0;
					while(l < n)
					{
						numbers[j][l] = i+1;
						l++;
					}
					count++;
				}
				k++;
			}
			j++;
		}
		if(count == n-1)
		{
			j = 0;
			while(j < n)
			{
				k = 0;
				while(k < n)
				{
					if(numbers[j][k]==0)
						mat[j][k] = i+1;
					k++;
				}
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	risoluzione_nmeno1(int **numbers, int **mat, int n)
{
	int	i;
	int	j;
	int	pos;
	int	count;

	i = 0;
	while(i < n)
	{
		
		j = 0;
		count = 0;
		while(j < n)
		{
			if(numbers[i][j] == 0)
			{
				numbers[i][j] = 1;
				pos = j;
				count++;
			}
			j++;
		}
		if(count == 1)
		{
			mat[i][pos] = n-1;
			return (1);
		}
		i++;
	}
	i = 0;
	while(i < n)
	{
		j = 0;
		count = 0;
		while(j < n)
		{
			if(numbers[j][i] == 0)
			{
				numbers[j][i] = 1;
				pos = j;
				count++;
			}
			else if(mat[i][j] != 0)
				numbers[i][j] = 1;
			j++;
		}
		if(count == 1)
		{
			mat[pos][i] = n-1;
			return (1);
		}
		i++;
	}
    return (0);
}

int	autocompletamento_nmeno1(int **input, int **mat, int n)
{
	int	i;
	int	j;
	int	k;
	int	ncount;
	int	count;
	int	**numbers = malloc(8*4);
	numbers[0] = malloc(4*4);
	numbers[1] = malloc(4*4);
	numbers[2] = malloc(4*4);
	numbers[3] = malloc(4*4);
	

	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			numbers[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while(i < 4)
	{
		
		j = 0;
		count = 0;
		while(j < n)
		{
			if(input[i][j] == n-1)
			{
				if(i == 0)
					numbers[0][j] = 1;
				else if(i == 1)
					numbers[n-1][j] = 1;
				else if(i == 2)
					numbers[j][0] = 1;
				else if(i == 3)
					numbers[j][n-1] = 1;
			}
			j++;
		}
		
		i++;
	}
	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			if(mat[i][j] == n-1)
			{
				k = 0;
				while(k < n)
				{
					numbers[k][j] = 1;
					k++;
				}
				k = 0;
				while(k < n)
				{
					numbers[i][k] = 1;
					k++;
				}
			}
			else if(mat[i][j] != 0)
				numbers[i][j] = 1;
			j++;
		}
		i++;
	}
	i = 0;
	count = 0;
	ncount = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			if(numbers[i][j]==0)
				count++;
			if(mat[i][j]==n-1)
				ncount++;
			j++;
		}
		i++;
	}
	if(n - ncount==count)
	{
		i = 0;
		while(i < n)
		{
			j = 0;
			while(j < n)
			{
				if(numbers[i][j]==0)
				{
					mat[i][j]=n-1;
					return (1);
				}
				j++;
			}
			i++;
		}
	}
	return (risoluzione_nmeno1(numbers, mat, n));
}

int	autocompletamento(int **input, int **mat, int n)
{
	return(autocompletamento_riga(mat, n) +
		autocompletamento_colonna(mat, n) +
		autocompletamento_sparsi(mat, n) +
		autocompletamento_nmeno1(input, mat, n));
}
