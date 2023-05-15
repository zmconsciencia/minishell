/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:35:28 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/15 15:00:04 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_last(void)
{
	t_program	*curr;

	curr = meta()->head;
	while (curr->next)
	{
		meta()->head = curr->next;
		free(curr);
		// apagar tambem os mallocs la dentro ??
		curr = meta()->head;
	}
	meta()->head = 0;
	free(curr);
}
