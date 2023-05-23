/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:54:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/23 11:46:03 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int	get_previous_fd(t_program *curr)
// {
// 	int			fd;
// 	t_program	*iterate;

// 	iterate = *list;
// 	while (iterate->i != curr->i - 1)
// 		iterate = iterate->next;
// 	close(iterate->fd[1]);
// 	fd = iterate->fd[0];
// 	return (fd);
// }

void	set_fd(t_program *curr)
{
	// if (curr->i == 2)
	// {
	// 	curr->fd[0] = open(argv[1], O_RDONLY);
	// 	if (curr->fd[0] == -1)
	// 	{
	// 		free_my_list(*list);
	// 		perror(argv[1]);
	// 		exit(0);
	// 	}
	// }
	// else
	// 	curr->fd[0] = get_previous_fd(curr, list);
	// if (curr-> i == argc - 2)
	// 	curr->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	curr->red.fd[0] = curr->red.fd_in;
	curr->red.fd[1] = curr->red.fd_out;
}
