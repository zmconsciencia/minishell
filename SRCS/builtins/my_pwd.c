/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:03 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/26 20:17:52 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(char **quoted_line)
{
	char	*buf;

	buf = 0;
	printf("%s\n", getcwd(buf, 0));
	free_lines(quoted_line);
	return (1);
}
