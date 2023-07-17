/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:57:58 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 18:50:58 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*trim_path(char *env_var)
{
	int		i;
	int		j;
	char	*trimed;

	i = 5;
	j = 0;
	trimed = malloc(sizeof(char) * (ft_strlen(env_var) - i + 1));
	if (!trimed)
		return (NULL);
	while (env_var[i])
		trimed[j++] = env_var[i++];
	trimed[j] = '\0';
	return (trimed);
}
