/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:36:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/08 14:01:45 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_exit(char **flags)
{
	long long	code;

	code = 0;
	meta()->exitcode = 0;
	clear_last();
	printf("exit\n");
	if (ft_isnum(flags[1]))
	{
		code = ft_atoi(flags[1]);
		exit(code);
	}
	else
		exit(meta()->exitcode);
}
