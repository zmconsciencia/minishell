/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:37:32 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/09 15:00:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_access(char **paths, char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	if (!paths)
		return (arg);
	temp = join_path(paths[i], arg);
	while (paths[i] && access(temp, F_OK))
	{
		free(temp);
		i++;
		if (!paths[i])
		{
			free_lines(paths);
			return (ft_strdup(arg));
		}
		temp = join_path(paths[i], arg);
	}
	i = 0;
	free_lines(paths);
	return (temp);
}
