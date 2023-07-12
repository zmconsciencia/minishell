/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/12 14:27:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_env_cd(char *cwd)
{
	int		i;
	char	*old;
	char	*new;
	char	*buf_new;
	char	*new_cwd;

	buf_new = 0;
	old = 0;
	new = 0;
	new_cwd = 0;
	new_cwd = getcwd(buf_new, 0);
	i = 0;
	while (meta()->envp[i])
	{
		if (!ft_strncmp(meta()->envp[i], "OLDPWD=", 7))
		{
			free(meta()->envp[i]);
			old = ft_strjoin("OLDPWD=", cwd);
			meta()->envp[i] = old;
			free(cwd);
			break ;
		}
		i++;
	}
	i = 0;
	while (meta()->envp[i])
	{
		if (!ft_strncmp(meta()->envp[i], "PWD=", 4))
		{
			free(meta()->envp[i]);
			new = ft_strjoin("PWD=", new_cwd);
			meta()->envp[i] = new;
			break ;
		}
		i++;
	}
	free(new_cwd);
}

int	my_cd(char **path)
{
	char	*buf;
	char	*cwd;

	buf = 0;
	meta()->exitcode = 0;
	if (count_strings(path) > 2)
	{
		ft_putstr_fd(" too many arguments\n", 2);
		meta()->exitcode = 1;
		return (-1);
	}
	if (path[1] == NULL)
		if (chdir("/") == 0)
			return (1);
	cwd = getcwd(buf, 0);
	if (chdir(path[1]) == 0)
	{
		change_env_cd(cwd);
		return (1);
	}
	else
	{
		perror(path[1]);
		meta()->exitcode = 1;
	}
	free(cwd);
	return (-1);
}

int	my_cd(char **path)
{
	char	*buf;
	char	*cwd;

	buf = 0;
	meta()->exitcode = 0;
	if (count_strings(path) > 2)
	{
		ft_putstr_fd(" too many arguments\n", 2);
		meta()->exitcode = 1;
		return (-1);
	}
	if (path[1] == NULL)
		if (chdir("/") == 0)
			return (1);
	cwd = getcwd(buf, 0);
	if (chdir(path[1]) == 0)
	{
		change_env_cd(cwd);
		return (1);
	}
	else
	{
		perror(path[1]);
		meta()->exitcode = 1;
	}
	free(cwd);
	return (-1);
}
