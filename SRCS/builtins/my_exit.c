/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:36:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/07 12:10:37 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_exit(char **flags)
{
	int	code;

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
