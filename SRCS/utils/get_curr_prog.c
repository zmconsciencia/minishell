/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_prog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:40:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/27 20:42:02 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_program	*get_curr_prog(int id)
{
	t_program	*curr;

	curr = program();
	while (curr->node_id != id)
		curr = curr->next;
	return (curr);
}
