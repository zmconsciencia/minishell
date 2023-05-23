/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:49:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 15:45:29 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_pot(char *token, t_program *node)
{
	int	i;

	i = -1;
	if (node->pot.program == 0)
	{
		node->pot.program = check_access(get_path(meta()->envp), token);
		node->pot.flags[0] = token;
	}
	else if (node->pot.flags[++i] == 0)
		node->pot.flags[i] = token;
	else
	{
		while (node->pot.flags[i] != 0)
			i++;
		node->pot.flags[i] = token;
	}
}
