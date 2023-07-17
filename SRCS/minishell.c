/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 18:47:12 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	start_function(char *g_line)
{
	char		**tokens;
	int			i;

	i = -1;
	meta()->treated = treat_and_replace(g_line);
	meta()->exitcode = 0;
	if (check_syntax(meta()->treated))
	{
		(meta())->nodes = ft_split(meta()->treated, 2);
		if (!meta()->nodes)
			return ;
		while (meta()->nodes[++i] != 0)
		{
			tokens = ft_split(meta()->nodes[i], 3);
			parse_nodes(tokens, i);
		}
		free_lines(meta()->nodes);
		free(meta()->treated);
		execute();
	}
	else
		free(meta()->treated);
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
	if (!new_env)
		return (0);
	while (str[i])
	{
		new_env[j] = malloc(sizeof(char) * (ft_strlen(str[i]) + 1));
		if (!new_env[j])
			return (0);
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
	meta()->envp = copy_arr(envp);
	if (ac >= 1)
	{
		rl_catch_signals = 0;
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
			add_history(g_line);
			start_function(g_line);
			g_line = readline("minishell> ");
		}
	}
	return (0);
}
