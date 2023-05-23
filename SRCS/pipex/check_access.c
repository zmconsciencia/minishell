/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:37:32 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 15:41:52 by jabecass         ###   ########.fr       */
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
		temp = join_path(paths[i], arg);
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free (paths);
	return (temp);
}
