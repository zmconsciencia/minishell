/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:09:29 by jabecass          #+#    #+#             */
/*   Updated: 2023/06/01 15:25:20 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	flag_parse(char *flag, char type)
{
	int	i;

	i = 1;
	if (flag[0] == '-')
	{
		while (flag[i])
		{
			if (flag[i] != type)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}