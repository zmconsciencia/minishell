/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/01 16:24:33 by jabecass         ###   ########.fr       */
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
	while (nodes[++i] != 0)
	{
		tokens = ft_split(nodes[i], 3);
		parse_nodes(tokens, i);
		// free_lines(tokens);
	}
	execute(); // --> tira se quiseres testar nodes
	// // free_nodes
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
				start_function(g_line);
			}
			clear_last();
			// free (g_line);
			g_line = readline("minishell> ");
		}
	}
	return (0);
}
