/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:52:12 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 17:34:40 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	do_builtin(t_program *curr)
{
	if (curr->red.fd_in == -1 || curr->red.fd_out == -1)
		meta()->exitcode = 1;
	if (is_builtin("cd", curr->pot.program))
		return (my_cd(curr->pot.flags));
	else if (is_builtin("echo", curr->pot.program))
		return (my_echo(curr));
	else if (is_builtin("env", curr->pot.program))
		return (my_env());
	else if (is_builtin("exit", curr->pot.program))
		my_exit(curr->pot.flags);
	else if (is_builtin("export", curr->pot.program))
		return (my_export(curr->pot.flags, curr));
	else if (is_builtin("pwd", curr->pot.program))
		return (my_pwd(curr->pot.flags));
	else if (is_builtin("unset", curr->pot.program))
		return (my_unset(curr->pot.flags));
	return (0);
}
