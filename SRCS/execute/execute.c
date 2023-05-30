/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/30 10:55:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute(void)
{
	t_program	*curr;
	int			n;

	curr = meta()->head;
	n = 0;
	while (curr)
	{
		// if (!check_builtin(curr))
		// // {
			pipex(curr);
			n++;
		// }
		curr = curr->next;
	}
	while (n > 0)
	{
		waitpid(-1, 0, 0);
		n--;
	}
}
