/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:57:58 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/09 14:19:12 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*trim_path(char *env_var)
{
	int		i;
	int		j;
	char	*trimed;

	i = 5;
	j = 0;
	trimed = malloc(sizeof(char) * (ft_strlen(env_var) - i + 1));
	while (env_var[i])
		trimed[j++] = env_var[i++];
	trimed[j] = '\0';
	return (trimed);
}
