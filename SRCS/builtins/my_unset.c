/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:09 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/12 17:04:03 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_me(int i)
{
	char	**new_env;
	int		j;
	int		k;

	j = 0;
	k = 0;
	new_env = malloc(sizeof(char *) * count_strings(meta()->envp));
	while (meta()->envp[j])
	{
		if (j == i)
			j++;
		if (meta()->envp[j])
		{
			new_env[k] = malloc(sizeof(char) * \
				ft_strlen(meta()->envp[j]) + 1);
			ft_strlcpy(new_env[k++], meta()->envp[j], \
				ft_strlen(meta()->envp[j]) + 1);
			j++;
		}
	}
	new_env[k] = 0;
	free_lines(meta()->envp);
	meta()->envp = new_env;
}

int	my_unset(char **flags)
{
	int		i;

	i = 0;
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
		unset_me(i);
	return (1);
}
