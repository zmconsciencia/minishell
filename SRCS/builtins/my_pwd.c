/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:03 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/13 18:54:34 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(char	**flags)
{
	char	*buf;

	buf = 0;
	(void)flags;
	buf = getcwd(0, 0);
	printf("%s\n", buf);
	free(buf);
	return (1);
}
