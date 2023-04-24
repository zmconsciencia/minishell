/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/24 15:44:11 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*g_line;

int	check_type(char *split)
{
	if (split[0] == '<' || split[0] == '>')
		return (OPERATOR);
	if (split[0] == '-')
		return (FLAG);
	if (split[0] == '|')
		return (PIPE);
	if (strcmp(split, "echo") || strcmp(split, "cd") || strcmp(split, "pwd") \
		|| strcmp(split, "export") || strcmp(split, "unset") || \
		strcmp(split, "env") || strcmp(split, "exit"))
		return (BUILTIN);
}

void	parse_split(char **split, t_program	**list)
{
	int			i;
	t_program	*node;
	t_program	*curr;

	i = -1;
	while (split[++i])
	{
		if (check_type(split[i]) == BUILTIN)
			run_builtin(split);
		else
		{
			node = malloc(sizeof(t_program));
			node->type = check_type(split[i]);
			if (node->type == OPERATOR)
				align_file(&node);
			if (node->type == PROGRAM)
				get_flags(&node);
		}
	}
}

void	go_function(char *g_line)
{
	// static t_program	**list;
	char				**split;
	int					i;

	i = -1;
	split = ft_split(g_line, ' ');
	while (split[++i])
		printf("%s\n", split[i]);
	// parse_split(split, &list);
}

// t_program	*program(void)
// {
// 	static t_program	program;

// 	return (&program);
// }

int	main(void) //como enviar char **envp sem os av/ac
{
	signal(SIGINT, SIG_DFL); // corrigir ^C
	signal(SIGQUIT, SIG_DFL); //falta tratar do ^D
	g_line = 0;
	g_line = readline("levishell> ");
	while (g_line)
	{
		if (g_line[0] != 0)
		{
			add_history(g_line);
			go_function(g_line);
		}
		free (g_line);
		g_line = readline("levishell> ");
	}
	return (0);
}


CCCCONNNNAAAAAAA