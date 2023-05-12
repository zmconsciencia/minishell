/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/12 11:39:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	go_function(char *g_line)
{
	char	*treated;
	char	**nodes;
	char	**tokens;
	int		i;

	i = -1;
	treated = treat_and_replace(g_line);
	nodes = ft_split(treated, 2);
	while (nodes[++i] != 0)
	{
		tokens = ft_split(nodes[i], 3);
		parse_nodes(tokens, i);
		free_lines(tokens);
	}
	// // free_nodes
	// // execute()
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
	meta()->envp = envp;
	if (ac == 1)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		g_line = 0;
		g_line = readline("minishell> ");
		while (g_line)
		{
			if (g_line[0] /* && check_syntax(g_line) */)
			{
				add_history(g_line);
				go_function(g_line);
			}
			// free (g_line); // ao fazer free na treat ja nao preciso fazer aqui, ou vice versa
			g_line = readline("minishell> ");
		}
	}
	return (0);
}
