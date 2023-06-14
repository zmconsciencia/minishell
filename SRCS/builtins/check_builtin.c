/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:53:33 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/14 14:41:50 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_builtin(t_program *curr)
{
	if (!curr->pot.program)
		return (0);
	if (is_builtin("cd", curr->pot.program))
		return (1);
	else if (is_builtin("echo", curr->pot.program))
		return (1);
	else if (is_builtin("env", curr->pot.program))
		return (1);
	else if (is_builtin("exit", curr->pot.program))
		return (1);
	else if (is_builtin("export", curr->pot.program))
		return (1);
	else if (is_builtin("pwd", curr->pot.program))
		return (1);
	else if (is_builtin("unset", curr->pot.program))
		return (1);
	return (0);
}
