/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crescenza.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:56:09 by scaiazzo          #+#    #+#             */
/*   Updated: 2022/07/24 19:56:17 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	crescenza_riga(int **input, int **mat, int n)
{
	int	i;
	int	j;
	int	sx;
	int	count;
	int	not_cons;
	int	numbers[n];
	//char	c;

	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			numbers[j] = j+1;
			j++;
		}
		j = 0;
		sx = 0;
		count=0;
		not_cons = 0;
		while(j < n)
		{
			if(mat[i][j] == n)
			{
				if(count == input[2][i] - 1 && input[2][i] != 1)
					sx = 1;
			}
			else if(mat[i][j]!=0 && sx == 0)
				not_cons=1;
			else if ( mat[i][j] == 0)
			{
				count++;
				if(sx == 1)
					not_cons = 1;
				if(count == 1 && j != 0 && mat[i][j-1] != n)
					not_cons = 1;
			}
			if(mat[i][j] != 0)
				numbers[mat[i][j]-1] = 0;
			j++;
		}
		if(sx == 1 && mat[i][0] == 0 && not_cons == 0)
		{
			j = 0;
			while(j < n)
			{
				sx=0;
				while(sx < n)
				{
					if(numbers[sx] != 0)
					{
						mat[i][j] = numbers[sx];
						numbers[sx] = 0;
						break;
					}
					sx++;
				}
				j++;
			}
			return (1);
		}
		else if(count == input[3][i] - 1  && mat[i][n-1] == 0 && !not_cons)
		{
			j = 0;
			while(j < count)
			{
				sx=0;
				while(sx < n)
				{
					if(numbers[sx] != 0)
					{
						mat[i][n-1-j] = numbers[sx];
						numbers[sx] = 0;
						break;
					}
					sx++;
				}
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	crescenza_colonna(int **input, int **mat, int n)
{
	int	i;
	int	j;
	int	sx;
	int	count;
	int	not_cons;
	int	numbers[n];
	
	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			numbers[j] = j+1;
			j++;
		}
		j = 0;
		sx = 0;
		count=0;
		not_cons=0;
		while(j < n)
		{
			if(mat[j][i] == n)
			{
				if(count == input[0][i] - 1 && input[0][i] != 1)
					sx = 1;
			}
			else if(mat[j][i]!=0 && sx == 0)
				not_cons=1;
			else
			{
				count++;
				if(sx == 1)
					not_cons = 1;
				if(count == 1 && j != 0 && mat[j-1][i] != n)
					not_cons = 1;
			}
			if(mat[j][i] != 0)
				numbers[mat[j][i]-1] = 0;
			j++;
		}
		if(sx && mat[0][i] == 0 && not_cons == 0)
		{
			j = 0;
			while(j < n)
			{
				sx=0;
				while(sx < n)
				{
					if(numbers[sx] != 0)
					{
						mat[j][i] = numbers[sx];
						numbers[sx] = 0;
						break;
					}
					sx++;
				}
				j++;
			}
			return (1);
		}
		else if(count == input[1][i] - 1 && mat[n-1][i] == 0 && not_cons == 0)
		{
			j = 0;
			while(j < count)
			{
				sx=0;
				while(sx < n)
				{
					if(numbers[sx] != 0)
					{
						mat[n-1-j][i] = numbers[sx];
						numbers[sx] = 0;
						break;
					}
					sx++;
				}
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	crescenza(int **input, int **mat, int n)
{
	return (crescenza_riga(input, mat, n) + crescenza_colonna(input, mat, n));
}
