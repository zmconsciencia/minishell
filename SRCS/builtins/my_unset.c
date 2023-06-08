/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/08 15:03:46 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_unset(char **flags)
{
	int		i;
	int		j;
	int		k;
	char	**new_env;

	i = 0;
	j = 0;
	k = 0;
	meta()->exitcode = 0;
	if (!flags[1])
		return (1);
	while (meta()->envp[i])
	{
		if (!ft_strncmp(meta()->envp[i], flags[1], ft_strlen(flags[1])))
			break ;
		i++;
	}
	if (i < count_strings(meta()->envp))
	{
		new_env = malloc(sizeof(char **) * count_strings(meta()->envp));
		while (meta()->envp[j])
		{
			if (j == i)
				j++;
			if (meta()->envp[j])
			{
				new_env[k] = malloc(sizeof(char *) * ft_strlen(meta()->envp[j]) + 1);
				ft_strlcpy(new_env[k++], meta()->envp[j], ft_strlen(meta()->envp[j]) + 1);
				j++;
			}
		}
		new_env[k] = 0;
		meta()->envp = new_env;
	}
	return (1); //ha de ser preciso fazer free disto
}
