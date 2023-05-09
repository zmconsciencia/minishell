/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_prog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:40:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/09 11:14:31 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_program	*get_curr_prog(int id)
{
	t_program	*curr = NULL;

	// curr = program();
	while (curr->node_id != id)
		curr = curr->next;
	return (curr);
}
