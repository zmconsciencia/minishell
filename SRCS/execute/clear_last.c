/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:35:28 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/15 14:59:14 by bde-seic         ###   ########.fr       */
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
