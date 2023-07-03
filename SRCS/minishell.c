/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/03 23:36:16 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	start_function(char *g_line)
{
	char		*treated;
	char		**nodes;
	char		**tokens;
	int			i;

	i = -1;
	treated = treat_and_replace(g_line);
	nodes = ft_split(treated, 2);
	if (!nodes)
		return ;
	while (nodes[++i] != 0)
	{
		tokens = ft_split(nodes[i], 3);
		free(nodes[i]); //alterado
		parse_nodes(tokens, i);
		// free_lines(tokens);
	}
	free(nodes); //alterado
	free(treated);
	execute();
	// free_lines(nodes); //alterado
}

char	**copy_arr(char **str)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (0);
	new_env = malloc(sizeof(char *) * (count_strings(str) + 1));
	while (str[i])
	{
		new_env[j] = malloc(sizeof(char) * (ft_strlen(str[i]) + 1));
		ft_strlcpy(new_env[j], str[i], ft_strlen(str[i]) + 1);
		j++;
		i++;
	}
	new_env[j] = 0;
	return (new_env);
}

t_meta	*meta(void)
{
	static t_meta	meta;

	return (&meta);
}

int	main(int ac, char **av, char **envp)
{
	char	*g_line;

	(void)av;
	meta()->envp = copy_arr(envp); //alterado (estava por baixo do void av)
	if (ac >= 1)
	{
		signal(SIGINT, sighandler);
		signal(SIGQUIT, sighandlerquit);
		g_line = 0;
		g_line = readline("minishell> ");
		while (1)
		{
			if (!g_line)
			{
				ft_putstr_fd("exit\n", 1);
				free_lines(meta()->envp);
				exit(0);
			}
			if (check_syntax(g_line))
			{
				add_history(g_line);
				start_function(g_line);
			}
			// clear_last();
			// free (g_line);
			g_line = readline("minishell> ");
		}
	}
	return (0);
}
