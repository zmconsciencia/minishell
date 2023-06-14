/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:48 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/14 14:41:59 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_env(void)
{
	int	i;

	i = 0;
	while (meta()->envp[i])
	{
		printf("%s\n", meta()->envp[i]);
		i++;
	}
	return (1);
}
