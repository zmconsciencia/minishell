/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/14 15:35:37 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**printable_export(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		arr[i] = ft_strcat("declare -x ", arr[i]);
		arr[i] = add_quotes(arr[i]);
		i++;
	}
	return (arr);
}

void	print_export(int fd)
{
	char	**env;
	int		i;
	int		n;

	i = 0;
	n = count_strings(meta()->envp);
	env = printable_export(sort_alpha(meta()->envp, n));
	while (env[i])
	{
		ft_putstr_fd(env[i], fd);
		ft_putstr_fd("\n", fd);
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
	new_env = malloc(sizeof(char *) * (count_strings(meta()->envp) + 2));
	while (env[i])
	{
		new_env[j] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		ft_strlcpy(new_env[j], env[i], ft_strlen(env[i]) + 1);
		j++;
		i++;
	}
	new_env[j] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strlcpy(new_env[j++], str, ft_strlen(str) + 1);
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

int	my_export(char **flags, t_program *curr)
{
	int	fd;

	fd = 1;
	if (curr->red.fd_out && !curr->program_id && !curr->next)
		fd = curr->red.fd_out;
	if (count_strings(flags) == 1)
		print_export(fd);
	else if (count_strings(flags) == 2)
	{
		if (!export_syntax(flags[1]))
			ft_putstr_fd(" not a valid identifier", 2);
		else
			add_var(flags[1]);
	}
	return (1);
}
