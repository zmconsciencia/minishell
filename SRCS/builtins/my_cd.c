/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/03 19:00:53 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Return Value: This command returns zero (0) on success. -1 is 
// returned on an error and errno is set appropriately. 

// melhorar alguns aspectos
int	my_cd(char **path)
{
	if (path[1] == NULL) // -> melhorar caso seja so cd
		if (chdir("/") == 0)
			return (1);
	if (chdir(path[1]) == 0)
		return (1);
	else
		printf("cd: no such file or directory: %s\n", path[0]);
	return (-1);
}
