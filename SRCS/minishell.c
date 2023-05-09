/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/09 13:29:44 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*add_three(char *g_line, int i)
{
	char	*new;
	int		y;
	int		x;

	y = 0;
	x = 0;
	new = malloc(sizeof(char) * ft_strlen(g_line) + 2);
	while (y < i)
		new[x++] = g_line[y++];
	new[x] = 3;
	x++;
	while (g_line[y])
		new[x++] = g_line[y++];
	new[x] = 0;
	free(g_line);
	return (new);
}

char	*treat_and_replace(char *g_line)
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
		{
			g_line = add_three(g_line, i++);
			while (ft_is_space(g_line[++i]) && \
				(g_line[i + 1] != '<' && g_line[i + 1] != '>'))
				;
		}
	}
	return (g_line);
}

void	go_function(char *g_line)
{
	char	*treated;
	char	**nodes;
	char	**tokens;
	int		i;
	int		j;

	i = -1;
	treated = treat_and_replace(g_line);
	nodes = ft_split(treated, 2); //splita por pipes
	while (nodes[++i] != 0)
	{
		tokens = ft_split(nodes[i], 3); //splita por espacos
		j = -1;
		while (tokens[++j])
			printf("%s\n", tokens[j]);
		printf("-------------------\n");
		j = -1;
		while (tokens[++j])
			parse_nodes(tokens, i);
		// free_tokens
	}
	// free_nodes
	// execute()
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
	(void)envp;

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
					go_function(g_line); // mandar envp ou usar global variable
			}
			// free (g_line); // ao fazer free na treat ja nao preciso fazer aqui, ou vice versa
			g_line = readline("minishell> ");
		}
	}
	return (0);
}
