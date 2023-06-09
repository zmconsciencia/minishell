/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:52:12 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/09 13:53:29 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	do_builtin(t_program *curr)
{
	if (is_builtin("cd", curr->pot.program))
		return (my_cd(curr->pot.flags));
	else if (is_builtin("echo", curr->pot.program))
		return (my_echo(curr)); //nao funcionou com $USER
	else if (is_builtin("env", curr->pot.program))
		return (my_env());
	else if (is_builtin("exit", curr->pot.program)) //ok!?
	{
		my_exit(curr->pot.flags);
		// clear_last();
		// printf("exit\n");
		// exit(0);
	}
	else if (is_builtin("export", curr->pot.program))
		return (my_export(curr->pot.flags));
	else if (is_builtin("pwd", curr->pot.program)) //ok!?
		return (my_pwd(curr->pot.flags));
	else if (is_builtin("unset", curr->pot.program))
		return (my_unset(curr->pot.flags));
	return (0);
}
