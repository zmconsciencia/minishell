/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:35:28 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/14 23:39:27 by bde-seic         ###   ########.fr       */
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
		curr = meta()->head;
	}
	// meta().fd_last = curr->red.fd_out;
	free(curr);
}