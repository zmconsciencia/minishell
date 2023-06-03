/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:03 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/03 18:54:31 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(char	**flags)
{
	char	*buf;

	buf = 0;
	if (flags[1])
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", getcwd(buf, 0));
	return (1);
}
