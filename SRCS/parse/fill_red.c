/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:50:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 09:49:03 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*retrieve_word(char *token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	while (token[i] != '<' || token[i] != '>')
		i--;
}

void	fill_red(char *token, int id)
{
	t_program	*curr;
	char		*operator;
	int			i;

	i = 0;
	curr = get_curr_prog(id);
	curr->red.operator = get_operator(token);
	curr->red.file_name = retrieve_word(token);
}
