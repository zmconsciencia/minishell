/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:45:26 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/26 18:59:33 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char	*builtin, char *quoted_line)
{
	int	i;

	i = 0;
	while (builtin[i] && quoted_line[i] && quoted_line[i] != ' ')
	{
		if (quoted_line[i] != builtin[i])
			return (0);
		i++;
	}
	if (!builtin[i] && (quoted_line[i] == ' ' || quoted_line[i] == '\0'))
		return (1);
	return (0);
}
