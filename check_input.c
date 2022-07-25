/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:55:59 by scaiazzo          #+#    #+#             */
/*   Updated: 2022/07/24 19:56:05 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int check_input(int **input, int n)
{
    int i;
    int j;
    int flag1;
    int flagn;

    //controllo degli angoli
    i = 0;
    if(((input[0][0]==1) ^ (input[2][0] == 1)) || ((input[0][n-1]==1) ^ (input[3][0] == 1)) ||
        ((input[2][n-1]==1) ^ (input[1][0] == 1)) || ((input[3][n-1]==1) ^ (input[1][n-1] == 1)))
        return (1);
    i = 0;
    while(i < 4)//controllo no doppioni
    {
        j = 0;
        flag1 = 0;
        flagn = 0;
        while(j < n)
        {
            if(input[i][j] == 1)
            {
                if(flag1)//errore
                    return (1);
                flag1 = 1;
            }
            else if(input[i][j] == n)
            {
                if(flagn)//errore
                    return (1);
                flagn = 1;
            }
            j++;
        }
        i++;
    }
    i = 0;
    flag1 = 0;
    flagn = 0;
    while(i < 4)//controllo #1 e #n
    {
        j = 0;
        while(j < n)
        {
            if(input[i][j] == 1)
            {
                flag1++;
            }
            else if(input[i][j] == n)
            {
                flagn++;
            }
            j++;
        }
        i++;
    }
    if(flag1 != 4 || flagn > 4)//se 1 diverso da 4 volte e n > 4 volte
    {
        return (1);
    }
    i = 0;
    while(i < 4)//controllo coppie nulle
    {
        j = 0;
        while(j < 4)
        {
            if(input[i][j] + input[i+1][j] > n+1 || input[i][j] + input[i+1][j] < 3)//somma delle coppie deve essere <= n+1 e => 3
                return (1);
            j++;
        }
        i+=2;
    }
    
    return (0);
}
