/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:21:37 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 00:22:13 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"microshell.h"

void    ft_puterr(char *err1, char *err2)
{
    int i;

    i = 0;
    while (err1[i])
    {
        write(2, &err1[i], 1);
        i++;
    }
    i = 0;
    while (err2[i])
    {
        write(2, &err2[i], 1);
        i++;
    }
    write(2, "\n", 1);
}

int get_next_cmd(char **av)
{
    int i;

    i = 0;
    while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
        i++;
    return (i);
}