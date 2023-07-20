/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:46:38 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 16:48:59 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"microshell.h"

void    execute(char **av, char **envp_, int in, int i)
{
    av[i] = NULL;
    dup2(in, 0);
    close(in);
    if (!execve(av[0], av, envp_))
        ft_puterr("error: fatal", "");
    ft_puterr("error: cannot execute ", av[0]);
}

void    handle_cd(char **av, int i)
{
     if (i != 2)
        ft_puterr("error: cd: bad arguments", "");
    else if (chdir(av[1]) == -1)
        ft_puterr("error: cd: cannot change directory to ", av[1]);
}

void    exec(char **av,char **envp_)
{
    int i;
    int in;
    int fd[2];
    int pid;
    
    i = 0;
    in = dup(0);
    while (av[i] && av[i + 1])
    {
        av = av + (i + 1);
        i = get_next_cmd(av);
        if (!strcmp(av[0], "cd"))
            handle_cd(av, i);
        else if ((i != 0 && !av[i]) || (i != 0 && !strcmp(av[i], ";")))
        {
            if (!(pid = fork()))
            {
                execute(av, envp_, in, i);
                return ;
            }
            else 
            {
                close(in);
                while(waitpid(pid, NULL, 0) != -1);
            }
            in = dup(0);
        }
        else if (i != 0 && !strcmp(av[i], "|"))
        {
            pipe(fd);
            if (!fork())
            {
                dup2(fd[1], 1);
                close(fd[1]);
                close(fd[0]);
                execute(av, envp_, in, i);
                return ;
            }
            else
            {
                close(fd[1]);
                close(in);
                in = fd[0];
            }
        }
    }
    close(in);
}

int main(int ac, char **av, char **envp)
{
    (void) ac;
    exec(av, envp);
    return (0);
}
