/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:49:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/09 14:45:19 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_pot(char *token, t_program *node)
{
	int	i;

	i = -1;
	if (node->pot.program == 0)
	{
		node->pot.program = ft_strdup(token);
		node->pot.path_program = check_access(get_path(meta()->envp), token);
		node->pot.flags[0] = ft_strdup(token);
	}
	else if (node->pot.flags[++i] == 0)
		node->pot.flags[i] = ft_strdup(token);
	else
	{
		while (node->pot.flags[i] != 0)
			i++;
		node->pot.flags[i] = ft_strdup(token);
	}
}
