/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/11 20:13:58 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_waitpid(int n)
{
	while (n > 0)
	{
		waitpid(-1, &(meta()->exitcode), WUNTRACED);
		meta()->exitcode = WEXITSTATUS(meta()->exitcode);
		n--;
	}
}

void	execute(void)
{
	t_program	*curr;
	int			n;
	int			len;

	curr = meta()->head;
	n = 0;
	len = lstsize(curr);
	meta()->exec = 0;
	if (!curr)
		meta()->exitcode = 0;
	while (curr)
	{
		if (check_builtin(curr) && len == 1)
			do_builtin(curr);
		else if (curr->pot.program)
		{
			meta()->exec = 1;
			pipex(curr);
			n++;
		}
		curr = curr->next;
	}
	my_waitpid(n);
	clear_last();
}
