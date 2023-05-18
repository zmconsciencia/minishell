/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_prog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:40:47 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/18 22:44:24 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_program	*get_curr_prog(int id)
{
	t_program	*curr;

	curr = meta()->head;
	while (curr->program_id != id)
		curr = curr->next;
	return (curr);
}
