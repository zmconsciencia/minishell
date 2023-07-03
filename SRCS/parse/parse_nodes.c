/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/03 23:23:05 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_program	*new_node(int id, int flag_no)
{
	t_program	*node;
	int			i;

	i = 0;
	node = malloc(sizeof(t_program));
	node->program_id = id;
	node->pot.program = 0;
	node->pot.path_program = 0;
	node->pot.flags = malloc(sizeof(char *) * (flag_no + 1));
	node->pot.flags[flag_no] = 0;
	while (i < flag_no)
		node->pot.flags[i++] = 0;
	node->red.fd_in = 0;
	node->red.fd_out = 0;
	node->red.here_doc = 0;
	node->red.limiter = 0;
	node->red.fd[0] = 0;
	node->red.fd[1] = 0;
	node->next = 0;
	return (node);
}

void	print_program(t_program *node)
{
	int	i;

	i = 0;
	printf("----------\n");
	printf("Node id: %d\n", node->program_id);
	printf("Program: %s\n", node->pot.program);
	printf("Program: %s\n", node->pot.path_program);
	while (node->pot.flags[i] != 0)
	{
		printf("Flags[%d]: %s\n", i, node->pot.flags[i]);
		i++;
	}
	printf("fd_in: %d\n", node->red.fd_in);
	printf("fd_out: %d\n", node->red.fd_out);
	printf("----------\n");
	if (node->next)
		print_program(node->next);
}

void	add_to_list(t_program *node)
{
	t_program	*curr;

	curr = meta()->head;
	if (!curr)
		meta()->head = node;
	else
	{
		while (curr->next != 0)
			curr = curr->next;
		curr->next = node;
		if (!curr->next)
			meta()->tail = node;
	}
}

int	count_flags(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (!ft_strchr(tokens[i], 5) || ft_strchr(tokens[i], 6))
			count++;
		i++;
	}
	return (count);
}

// A FUNCAO EXPANDED_DOLLAR RETORNA UM MALLOC, QUE VAI PRECISAR SER FREED
void	parse_nodes(char **tokens, int id)
{
	int			pid;
	int			i;
	int			flag_no;
	char		*temp;
	t_program	*node;

	i = -1;
	meta()->hc = 0;
	flag_no = count_flags(tokens);
	node = new_node(id, flag_no);
	while (tokens[++i])
	{
		if (ft_strchr(tokens[i], 6) || ft_strchr(tokens[i], 5))
			fill_red(tokens[i], node);
		else if (ft_strchr(tokens[i], '\"') || ft_strchr(tokens[i], '\''))
		{
			temp = treat_quotes(tokens[i]);
			fill_pot(temp, node);
			free(temp);
		}
		else
			fill_pot(tokens[i], node);
	}
	if (node->red.here_doc)
	{
		meta()->hc = 1;
		pid = fork();
		if (!pid)
		{
			signal(SIGQUIT, SIG_IGN);
			signal(SIGINT, sighandlerhc);
			run_heredoc(node->red.limiter, node);
			free(node->red.limiter);
			exit(0);
		}
		else
		{
			waitpid(0, 0, 0);
			free(node->red.limiter);
			signal(SIGINT, sighandler);
			signal(SIGQUIT, sighandlerquit);			
		}
	}
	add_to_list(node);
	free_lines(tokens);
}
