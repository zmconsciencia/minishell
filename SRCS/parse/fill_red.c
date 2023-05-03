/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:50:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 19:32:53 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_op_type(char *token)
{
	int		i;
	char	op;

	i = 0;
	op = token[0];
	if (op == '>')
	{	
		while (token[i])
			if (token[i++] == '<')
				return (1);
	}
	else if (op == '<')
	{
		while (token[i])
			if (token[i++] == '>')
				return (1);
	}
	return (0);
}

// void	fill_red2(char *token, int node_id)
// {
// 	char		**tab;
// 	char		operator;
// 	int			i;

// 	i = 0;
// 	operator = get_operator(token);
// 	tab = ft_split(token, operator);
// 	fill_pot(tab[0], node_id);
// 	while (tab[i])
// 		fill_red(new_strjoin(operator, tab[i++]), node_id);
// 	free_lines(tab);
// }

// void	fill_red(char *token, int id)
// {
// 	t_program	*curr;
// 	char		operator;
// 	int			i;
// 	char		**infiles;
// 	char		**outfiles;
// 	int			fd;

// 	i = 0;
// 	curr = get_curr_prog(id);
// 	operator = token[0];
// 	if (count_op_type(token))
// 	{
// 		infiles = ft_split(token, '<');
// 		outfiles = ft_split(token, '>');
// 	}
// 	else
// 		if (token[0] == '<')
// 			infiles = ft_split(token, '<')
// 		else
// 			outfi
// 	tab = ft_split(token, operator);
// 	while(tab[i])
// 	{
// 		if (token[0] == '<')
// 			curr->red.fd[0] = open(tab[i], O_RDONLY); // completar flags
// 		if (tab[++i])
// 			close(curr->red.fd[0]);
// 	}

	
// 	curr->red.operator = get_operator(token);
// 	curr->red.file_name = retrieve_word(token);
	
// }
