/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:47:58 by jabecass          #+#    #+#             */
/*   Updated: 2023/06/09 13:12:52 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_red(char *token, t_program *node)
{
	char	*file_name;
	char	*op;

	file_name = get_filename(token);
	op = get_op(token);
	if (ft_strlen(op) == 1)
	{
		if (op[0] == 5/* ft_strncmp(op, 6, 1) == 0 */)
			treat_infiles(file_name, node);
		else
			treat_outfiles(file_name, node);
	}
	else if (ft_strlen(op) == 2)
	{
		if (op[0] == 5/* ft_strncmp(op, 6, 1) == 0 */)
		{
			node->red.limiter = file_name;
			node->red.here_doc++;
		}
		else
			treat_append(file_name, node);
	}
	if (!node->red.here_doc)
		free(file_name);
	free(op);
}
