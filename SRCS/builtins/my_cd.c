/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:34 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/15 15:31:03 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Return Value: This command returns zero (0) on success. -1 is 
// returned on an error and errno is set appropriately. 

// melhorar alguns aspectos
int	my_cd(char **path)
{
	if (!path[0]) // -> melhorar caso seja so cd
		if (chdir(0) == 0)
			return (1);
	if (chdir(path[0]) == 0)
		return (1);
	else
		printf("cd: no such file or directory: %s\n", path[0]);
	return (-1);
}
