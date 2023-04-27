/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:53:33 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/26 20:20:27 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_builtin(char	**quoted_line)
{
	if (is_builtin("cd", quoted_line[0]))
		return (printf("builtin: cd\n"));
	else if (is_builtin("echo", quoted_line[0]))
		return (my_echo(quoted_line));
	else if (is_builtin("env", quoted_line[0]))
		return (printf("builtin: env\n"));
	else if (is_builtin("exit", quoted_line[0]))
		exit(EXIT_FAILURE); //not this one
	else if (is_builtin("export", quoted_line[0]))
		return (printf("builtin: export\n"));
	else if (is_builtin("pwd", quoted_line[0]))
		return (my_pwd(quoted_line));
	else if (is_builtin("unset", quoted_line[0]))
		return (printf("builtin: unset\n"));
	return (0);
}
