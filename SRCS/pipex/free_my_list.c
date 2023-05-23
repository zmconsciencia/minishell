/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_my_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:59 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 11:45:48 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	free_my_list(t_program *list)
// {
// 	t_program	*curr;
// 	int			i;

// 	curr = list;
// 	while (curr)
// 	{
// 		close(curr->fd[0]);
// 		close(curr->fd[1]);
// 		list = curr->next;
// 		free(curr->path);
// 		i = 0;
// 		while (curr->flags[i])
// 			free(curr->flags[i++]);
// 		free(curr->flags);
// 		free(curr);
// 		curr = list;
// 	}
// 	free (list);
// }
