/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assegnazioni_sicure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:55:27 by scaiazzo          #+#    #+#             */
/*   Updated: 2022/07/24 19:55:33 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void assegnazioni_sicure(int **input, int **mat, int n)
{
    int i;
    int j;
    int k;
    int col;

    i = 0;
    while(i < 4)
    {
        j = 0;
        while(j < n)
        {
            if(input[i][j] == n)//controllo dei n
            {
                if(i < 2)
                    col = 1;
                else
                    col = 0;
                if(!(i%2))
                {
                    k = 0;
                    while(k < n)
                    {
                        if(col)
                            mat[k][j] = k + 1;
                        else
                            mat[j][k] = k + 1;
                        k++;
                    }
                }
                else
                {
                    k = 0;
                    while(k < n)
                    {
                        if(col)
                            mat[k][j] = n - k;
                        else
                            mat[j][k] = n - k;
                        k++;
                    }
                }
               
            }
            if(input[i][j] == 1)//controllo degli 1
            {
                if(i == 0)
                    mat[0][j] = n;
                else if(i == 1)
                    mat[n-1][j] = n;
                else if(i == 2)
                    mat[j][0] = n;
                else
                    mat[j][n-1] = n;
            }
            
            if(input[i][j] == 2)//controllo dei 2-1
            {
                if(i%2 && input[i-1][j] == 1)
                {
                    if(i == 1)
                        mat[n-1][j] = n-1;
                    else
                        mat[j][n-1] = n-1;

                }
                else if(!(i%2) && input[i+1][j] == 1)
                {
                    if(i == 0)
                        mat[0][j] = n-1;
                    else
                        mat[j][0] = n-1;
                   
                }
            }//controllo sum n+1
            if(i == 0 || i == 2)
            {
		    if(i==0 && input[i][j] + input[i+1][j] == n+1)
		        mat[input[i][j]-1][j] = n;
		    else if(input[i][j] + input[i+1][j] == n+1)
		        mat[j][input[i][j]-1] = n;
	    }
            j++;
        }
        i++;
    }
}
