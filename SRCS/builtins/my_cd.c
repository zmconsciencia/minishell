/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 10:38:28 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	change_env_cd(char *old_cwd, char *new_cwd1)
{
	int		i;
	char	*old;
	char	*new;

	i = -1;
	while (meta()->envp[++i])
	{
		if (!ft_strncmp(meta()->envp[i], "OLDPWD=", 7))
		{
			free(meta()->envp[i]);
			old = ft_strjoin("OLDPWD=", old_cwd);
			meta()->envp[i] = old;
			free(old_cwd);
		}
		else if (!ft_strncmp(meta()->envp[i], "PWD=", 4))
		{
			free(meta()->envp[i]);
			new = ft_strjoin("PWD=", new_cwd1);
			meta()->envp[i] = new;
		}
	}
	free(new_cwd1);
	return (1);
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
	cwd = getcwd(buf, 0);
	if (path[1] == NULL && chdir("/") == 0 && \
		change_env_cd(cwd, getcwd(buf, 0)))
		return (1);
	if (chdir(path[1]) == 0 && change_env_cd(cwd, getcwd(buf, 0)))
		return (1);
	else
	{
		perror(path[1]);
		meta()->exitcode = 1;
	}
	free(cwd);
	return (-1);
}
