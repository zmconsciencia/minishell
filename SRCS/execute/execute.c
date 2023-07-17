/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:25:01 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 17:58:23 by jabecass         ###   ########.fr       */
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

void	end(t_program *curr)
{
	do_builtin(curr);
	if (curr->red.fd_in > 2)
		close(curr->red.fd_in);
	if (curr->red.fd_out > 2)
		close(curr->red.fd_out);
}

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
		if (check_builtin(curr) && (len == 1 && (!(curr->red.fd_in && \
			curr->red.fd_out) || !ft_strncmp("cd", curr->pot.program, 2))))
			end(curr);
		else if (curr->pot.program)
		{
			meta()->exec = 1;
			pipex(curr);
			n++;
		}
		curr = curr->next;
	}
	my_waitpid(n);
	meta()->exec = 0;
	clear_last();
}
