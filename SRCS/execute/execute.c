/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/15 15:09:19 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute(void)
{
	t_program	*curr;

	curr = meta()->head;
	// printf("passei por aqui\n");
	while (curr)
	{
		// printf("vou procurar por: %s\n", curr->pot.program);
		if (!check_builtin(curr))
		{
			printf("vou entrar no pipex\n");
			//pipex(curr)
		}
		curr = curr->next;
	}
}
