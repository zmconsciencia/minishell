/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:53:33 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/30 11:42:37 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// mudar is_builtin para ft_strncmp?
int	check_builtin(t_program *curr)
{
	if (is_builtin("cd", curr->pot.program))
		return (my_cd(curr->pot.flags));
	else if (is_builtin("echo", curr->pot.program))
		return (my_echo(curr)); //nao funcionou com $USER
	else if (is_builtin("env", curr->pot.program))
		return (my_env());
	else if (is_builtin("exit", curr->pot.program)) //ok!?
	{
		clear_last();
		printf("exit\n");
		exit(0);
	}
	else if (is_builtin("export", curr->pot.program))
		return (printf("builtin: export\n"));
	else if (is_builtin("pwd", curr->pot.program)) //ok!?
		return (my_pwd(curr->pot.flags));
	else if (is_builtin("unset", curr->pot.program))
		return (printf("builtin: unset\n"));
	return (0);
}


// int	check_builtin(t_program *curr)
// {
// 	// if (!ft_strncmp("cd\0", curr->pot.program, ft_strlen(curr->pot.program)))
// 	if (is_builtin("cd", curr->pot.program))
// 		return (printf("builtin: cd\n"));
// 	else if (ft_strncmp("echo", curr->pot.program, ft_strlen(curr->pot.program)))
// 		return (my_echo(curr->pot.flags));
// 	else if (ft_strncmp("env", curr->pot.program, ft_strlen(curr->pot.program)))
// 		return (printf("builtin: env\n"));
// 	else if (ft_strncmp("exit", curr->pot.program, ft_strlen(curr->pot.program)))
// 		exit(EXIT_FAILURE); //not this one
// 	else if (ft_strncmp("export", curr->pot.program, ft_strlen(curr->pot.program)))
// 		return (printf("builtin: export\n"));
// 	else if (ft_strncmp("pwd", curr->pot.program, ft_strlen(curr->pot.program)))
// 		return (my_pwd());
// 	else if (ft_strncmp("unset", curr->pot.program, ft_strlen(curr->pot.program)))
// 		return (printf("builtin: unset\n"));
// 	return (0);
// }
