/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:37:32 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/26 18:01:02 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_access(char **paths, char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	temp = join_path(paths[i], arg);
	while (paths[i] && access(temp, F_OK))
	{
		free(temp);
		i++;
		if (!paths[i])
			return (arg);
		temp = join_path(paths[i], arg);
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free (paths);
	return (temp);
}
