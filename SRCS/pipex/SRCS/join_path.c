/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:51:24 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/08 13:09:40 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*str_trim(char *string)
{
	int		i;
	char	*complete;

	i = 0;
	while (string[i] && string[i++] != ' ')
	{
	}
	complete = malloc(sizeof(char) * i + 1);
	i = -1;
	while (string[++i] && string[i] != ' ')
		complete[i] = string[i];
	complete[i] = 0;
	return (complete);
}

char	*join_path(char *path, char *arg)
{
	char	*complete;
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(path, "/");
	temp2 = ft_strjoin(temp, arg);
	free(temp);
	complete = str_trim(temp2);
	free(temp2);
	return (complete);
}
