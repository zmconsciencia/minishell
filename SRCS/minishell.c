/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 19:44:46 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	treat_and_replace(char *g_line)
{
	int	i;

	i = -1;
	while (g_line[++i])
	{
		if (g_line[i] == '|')
			g_line[i] = 2;
		if (g_line[i] == ' ')
			g_line[i] = 3;
		if (g_line[i] == '\"')
			while (g_line[++i] != '\"' && g_line[i] != 0)
				i++;
		if (g_line[i] == '\'')
			while (g_line[++i] != '\'' && g_line[i] != 0)
				i++;
		if (g_line[i] == '<' || g_line[i] == '>')
			while (ft_is_space(g_line[++i]))
				;
	}
}

void	go_function(char *g_line)
{
	char	**nodes;
	char	**tokens;
	int		i;
	int		j;

	i = -1;
	treat_and_replace(g_line);
	nodes = ft_split(g_line, 2); //splita por pipes
	while (nodes[++i] != 0)
	{
		tokens = ft_split(nodes[i], 3); //splita por espacos
		j = -1;
		while (tokens[++j])
			printf("%s\n", tokens[j]);
		// parse_nodes(tokens, i);
		// free_tokens
	}
	// free_nodes
	// execute()
}

t_program	*program(void)
{
	static t_program	program;

	return (&program);
}

int	main(int ac, char **av, char **envp)
{
	char	*g_line;
	(void)av;
	(void)envp;

	if (ac == 1)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		g_line = 0;
		g_line = readline("minishell> ");
		while (g_line)
		{
			if (check_syntax(g_line))
			{
				if (g_line[0] != 0)
				{
					add_history(g_line);
					go_function(g_line); // mandar envp ou usar global variable
				}
			}
			free (g_line);
			g_line = readline("minishell> ");
		}
	}
	return (0);
}
