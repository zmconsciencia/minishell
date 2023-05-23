/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 16:32:41 by jabecass         ###   ########.fr       */
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
		if (!check_builtin(curr))
		{
			pipex(curr);
			n++;
		}
		curr = curr->next;
	}
	while (n-- > 0)
		waitpid(-1, 0, 0);
}
