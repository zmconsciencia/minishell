/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:51:24 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 18:50:52 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*str_trim(char *string)
{
	int		i;
	char	*complete;

	i = 0;
	while (string[i] && string[i++] != ' ')
	{
	}
	complete = malloc(sizeof(char) * i + 1);
	if (!complete)
		return (NULL);
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
