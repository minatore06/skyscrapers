/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:55:49 by scaiazzo          #+#    #+#             */
/*   Updated: 2022/07/24 19:55:55 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	brute(int **mat, int **sure, int n, int error)
{
	int	i;
	int	j;
	int	k;
	int	no;
	int	number;
	int	numbers[n];

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
			if(number > n)
			{
				j++;
				number=number-n;
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
