#include <stdio.h>
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

void	autocompletamento(int **mat, int n)
{
	while(autocompletamento_riga(mat, n) ||
		autocompletamento_colonna(mat, n) ||
		autocompletamento_sparsi(mat, n))
	{}
}
