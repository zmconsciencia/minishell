/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:48 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/06 16:40:39 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_env(void)
{
	int	i;

	i = 0;
	while (meta()->envp[i])
	{
		printf("%s\n", meta()->envp[i]); //nao esta a imprimir na ordem certa
		i++;
	}
	return (1);
}
