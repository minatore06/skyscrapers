#include <stdio.h>
#include <unistd.h>
void	brute(int **mat, int **sure, int n, int error)
{
	int	i;
	int	j;
	int	k;
	int	sos;
	int	sas;
	int	no;
	int	number;
	int	numbers[n];
	//char	c;
	
						sos=0;
					    	while(sos<4){
						sas=0;
						while(sas<4)
						{
						    printf("%d  ", mat[sos][sas]);
						    sas++;
						}
						printf("\n");
						sos++;
					    }
						printf("\n");
	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			if(sure[i][j] == 0)
				mat[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while(i < n)
	{
		numbers[i]=i+1;
		i++;
	}
	i = 0;
	while(i < n)
	{
		j = 0;
		number = error;
		while(j < n)
		{	
			no = 0;
			if(sure[i][j] == 1)
			{
				j++;
				continue;
			}
			if(number/n > 0)
			{
				j++;
				number=number/(n+1);
				continue;
			}
			k = 0;
			while(k < n)
			{
				if(number >= n)
				{
					number = 0;
					while(number<n)
					{
						if(numbers[number] != 0)
							break;
						number++;
					}
					if(number == n)
					{
						number = 0;
						brute(mat, sure, n, ++error);
						no = 1;
						break;
					}
				}
				if((mat[i][k] == numbers[number] && k != j) || 
					(mat[k][j] == numbers[number] && k != i))
				{	
					if(mat[i][j] == numbers[number])
						mat[i][j] = 0;
					numbers[number] = 0;
					k = 0;
					number++;
					continue;
				}
				k++;
			}
			if(no != 1)
			{
				mat[i][j] = numbers[number];
				number++;
			}
			j++;
		}
		i++;
	}
}
