/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:36 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 17:48:03 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	treat_infiles(char *file_name, t_program *node)
{
	if (node->red.fd_in != 0 && node->red.fd_in != -1)
		close(node->red.fd_in);
	node->red.fd_in = open(file_name, O_RDONLY);
	if (node->red.fd_in == -1)
	{
		if (meta()->exitcode != 1)
			perror(file_name);
		meta()->exitcode = 1;
	}
}

void	treat_outfiles(char *file_name, t_program *node)
{
	if (meta()->exitcode == 1)
		return ;
	if (node->red.fd_out != 0)
		close(node->red.fd_out);
	node->red.fd_out = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (node->red.fd_out == -1)
	{
		meta()->exitcode = 1;
		perror(file_name);
	}
}

void	treat_append(char *file_name, t_program *node)
{
	if (meta()->exitcode == 1)
		return ;
	if (node->red.fd_out != 0)
		close(node->red.fd_out);
	node->red.fd_out = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (node->red.fd_out == -1)
	{
		meta()->exitcode = 1;
		perror(file_name);
	}
}
