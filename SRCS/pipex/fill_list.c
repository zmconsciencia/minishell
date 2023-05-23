/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:56:43 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 11:46:57 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	fill_list(t_program **list, int argc, char **argv, char **envp)
// {
// 	int			i;
// 	t_program	*node;
// 	t_program	*curr;

// 	i = 2;
// 	while (i <= argc - 2)
// 	{
// 		node = malloc(sizeof(t_program));
// 		node->i = i;
// 		node->fd[0] = 0;
// 		node->fd[1] = 0;
// 		node->path = check_access(get_path(envp), argv[i]);
// 		node->flags = ft_split(argv[i], ' ');
// 		node->next = 0;
// 		if (!(*list))
// 			*list = node;
// 		else
// 		{
// 			curr = *list;
// 			while (curr->next != 0)
// 				curr = curr->next;
// 			curr->next = node;
// 		}
// 		i++;
// 	}
// }
