/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/15 00:17:52 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute(int node_id)
{
	t_program	*curr;
	
	(void)node_id;
	curr = meta()->head;
	// curr = get_curr_prog(node_id);
	printf("passei por aqui\n");
	while (curr)
	{
		printf("vou procurar por: %s\n", curr->pot.program);
		if (!check_builtin(curr))
		{
			printf("vou entrar no pipex\n");
			//pipex(curr)
		}
		curr = curr->next;
	}
	// clear_last();
	// apagar programas
}