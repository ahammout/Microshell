/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:19:41 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 00:22:22 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
#define MICROSHELL_H

#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>

void    ft_puterr(char *err1, char *err2);
int     get_next_cmd(char **av);

#endif