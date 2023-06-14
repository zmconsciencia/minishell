/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:35:28 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/14 15:48:08 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_last(void)
{
	t_program	*curr;

	curr = meta()->head;
	while (curr)
	{
		meta()->head = curr->next;
		free(curr->pot.program);
		free(curr->pot.path_program);
		free_lines(curr->pot.flags);
		free(curr);
		curr = meta()->head;
	}
	meta()->head = 0;
	free(curr);
}
