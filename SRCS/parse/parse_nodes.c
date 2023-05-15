/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:42:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/14 23:16:25 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_program	*new_node(int id, int flag_no)
{
	t_program	*node;
	int			i;

	i = 0;
	node = malloc(sizeof(t_program));
	node->node_id = id;
	node->pot.program = 0;
	node->pot.flags = malloc(sizeof(char *) * flag_no + 1);
	while (i < flag_no)
		node->pot.flags[i++] = 0;
	node->red.fd_in = 0;
	node->red.fd_out = 0;
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
	printf("Node id: %d\n", node->node_id);
	printf("Program: %s\n", node->pot.program);
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

	if (meta()->head == 0)
		meta()->head = node;
	else
	{
		curr = meta()->head;
		while (curr->next != 0)
			curr = curr->next;
		curr->next = node;
	}
	meta()->tail = node;
}

int	count_flags(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (!ft_strchr(tokens[i], '>') || ft_strchr(tokens[i], '<'))
			count++;
		i++;
	}
	return (count);
}

// A FUNCAO EXPANDED_DOLLAR RETORNA UM MALLOC, QUE VAI PRECISAR SER FREED
void	parse_nodes(char **tokens, int id)
{
	int			i;
	int			flag_no;
	t_program	*node;

	i = -1;
	flag_no = count_flags(tokens);
	node = new_node(id, flag_no);
	while (tokens[++i])
	{
		if (ft_strchr(tokens[i], '>') || ft_strchr(tokens[i], '<'))
			treat_redirect(tokens[i], node);
		else if (ft_strchr(tokens[i], '\"') || ft_strchr(tokens[i], '\''))
			fill_pot(treat_quotes(tokens[i]), node);
		else
			fill_pot(tokens[i], node);
		// printf("%s\n", tokens[i]); --> tirar
	}
	add_to_list(node);
	// print_program(node); // --> tirar
	//fazer free token list (**), e fazer free de cada token dentro do fill pot ou fill red
} 
