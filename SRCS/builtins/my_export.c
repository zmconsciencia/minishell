/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/12 11:30:17 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**sort_alpha(char **arr, int size)
{
	int		i;
	int		swapped;
	char	*temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strncmp(arr[i], arr[i + 1], ft_strlen(arr[i])) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		size--;
	}
	return (arr);
}

void	print_export(void)
{
	char	**env;
	int		i;
	int		n;

	i = 0;
	n = count_strings(meta()->envp);
	env = sort_alpha(meta()->envp, n);
	while (env[i])
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
}

void	add_var(char *str)
{
	char	**env;
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = meta()->envp;
	new_env = malloc(sizeof(char **) * count_strings(meta()->envp) + 2);
	while (env[i])
	{
		new_env[j] = malloc(sizeof(char) * (strlen(env[i]) + 1));
		strcpy(new_env[j], env[i]);
		j++;
		i++;
	}
	new_env[j] = malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(new_env[j++], str);
	new_env[j] = NULL;
	meta()->envp = new_env;
}

int	export_syntax(char *str)
{
	int	i;

	i = 0;
	meta()->exitcode = 0;
	if (str[0] != '_' && !ft_isalpha(str[0]))
	{
		meta()->exitcode = 1;
		return (0);
	}
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '-')
		{
			meta()->exitcode = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	my_export(char **flags)
{
	if (count_strings(flags) == 1)
		print_export();
	else if (count_strings(flags) == 2)
	{
		if (!export_syntax(flags[1]))
			ft_putstr_fd(" not a valid identifier", 2);
		else
			add_var(flags[1]);
	}
	return (1);
}
