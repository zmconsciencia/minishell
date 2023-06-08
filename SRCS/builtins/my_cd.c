/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/08 17:32:59 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Return Value: This command returns zero (0) on success. -1 is 
// returned on an error and errno is set appropriately. 

// melhorar alguns aspectos
int	my_cd(char **path)
{
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
	if (chdir(path[1]) == 0)
		return (1);
	else
	{
		perror(path[1]);
		meta()->exitcode = 1;
	}
	return (-1);
}
