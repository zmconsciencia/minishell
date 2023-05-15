/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:03 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/15 15:08:58 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(char	**flags)
{
	char	*buf;

	buf = 0;
	if (flags[0])
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", getcwd(buf, 0));
	return (1);
}
