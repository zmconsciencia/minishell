/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:11:18 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/24 18:21:22 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	check_type(char *split)
// {
// 	if (split[0] == '<' || split[0] == '>')
// 		return (OPERATOR);
// 	if (split[0] == '-')
// 		return (FLAG);
// 	if (split[0] == '|')
// 		return (PIPE);
// 	if (strcmp(split, "echo") || strcmp(split, "cd") || strcmp(split, "pwd") \
// 		|| strcmp(split, "export") || strcmp(split, "unset") || \
// 		strcmp(split, "env") || strcmp(split, "exit"))
// 		return (BUILTIN);
// }

// void	parse_split(char **split, t_program	**list)
// {
// 	int			i;
// 	t_program	*node;
// 	t_program	*curr;

// 	i = -1;
// 	while (split[++i])
// 	{
// 		if (check_type(split[i]) == BUILTIN)
// 			program().type = ;
// 		// else
// 		// {
// 		// 	node = malloc(sizeof(t_program));
// 		// 	node->type = check_type(split[i]);
// 		// 	if (node->type == OPERATOR)
// 		// 		align_file(&node);
// 		// 	if (node->type == PROGRAM)
// 		// 		get_flags(&node);
// 		// }
// 	}
// }

void	go_function(char *g_line)
{
	// static t_program	**list;
	char				**split;
	int					i;

	i = -1;
	split = ft_split(g_line, '|');
	while (split[++i])
		printf("%s\n", split[i]);
	// parse_split(split, &list);
}

t_program	*program(void)
{
	static t_program	program;

	return (&program);
}

int		count_tokens(char *g_line)
{
	int i = 0;
	int tokens = 0;
	while (g_line[i])
	{
		if (g_line[i] == '"' || g_line == '<' || g_line == '>')
			tokens++;
		i++;
	}
	return(tokens)
}

char	*handle_infile(char *str)
{
	int i = 0;
	char *t = NULL;
	int j = 0;
	int fd;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
	{
		t[j] = str[i];
		j++;
		i++;
	}
	t[j] ='\0';
	return(t);
}

void	opens(char *infile)
{
	int fd = open(infile, O_RDONLY);
	if (!fd)
	{
		//faz qq coisa
	}
}

//signals estao mal fzer 

int	main(int ac, char **av, char **envp)
{
	(void)av;
	(void)envp;
	if (ac == 1)
	{
		char *g_line;
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		g_line = 0;
		g_line = readline("minishell> ");
		while (g_line)
		{
			if (g_line[0] != 0)
			{
				add_history(g_line);
				go_function(g_line);
			}
			free (g_line);
			g_line = readline("minishell> ");
		}
	}
	return (0);
}


//printf("%s: %d", carater/string/comando, tipo);