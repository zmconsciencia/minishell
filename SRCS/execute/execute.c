/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/14 14:10:31 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute(void)
{
	t_program	*curr;
	int			n;
	int			len;

	curr = meta()->head;
	n = 0;
	len = lstsize(curr);
	while (curr)
	{
		if (check_builtin(curr) && len == 1)
			do_builtin(curr);
		else if (curr->pot.program)
		{
			pipex(curr);
			n++;
		}
		curr = curr->next;
	}
	while (n > 0)
	{
		waitpid(-1, &(meta()->exitcode), WUNTRACED);
		// if (WIFEXITED(meta()->exitcode) || 1)
			meta()->exitcode = WEXITSTATUS(meta()->exitcode);
		n--;
	}
}
