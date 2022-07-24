#include <stdio.h>
#include <unistd.h>
void	brute(int **mat, int **sure, int n, int error)
{
	int	i;
	int	j;
	int	k;
	int	inc;
	int	number;
	char	c;
	
	i = 0;
	inc = 1;
	while(i < n)
	{
		j = 0;
		number = 1 + error;
		while(j < n)
		{	
			if(sure[i][j] == 1)
			{
				j++;
				continue;
			}
			if(number/n > 0)
			{
				j++;
				number/=n;
				inc = number;
				continue;
			}
			k = 0;
			while(k < n)
			{
				if(number >= n)
				{
					number = inc;
					brute(mat, sure, n, ++error);
					break;
				}
				if((mat[i][k] == number && k != j) || (mat[k][j] == number && k != i))
				{	
					if(mat[i][j] == number)
						mat[i][j] = 0;
					k = 0;
					number++;
					continue;
				}
				else {
					c = number + 48;
					write(1, &c, 1);
					mat[i][j] = number;
				}
				k++;
			}
			write(1, "\n", 1);
			j++;
		}
		i++;
	}
}
