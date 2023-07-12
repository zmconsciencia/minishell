/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/12 16:30:16 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		else if (!if_exists(flags[1]))
			add_var(flags[1]);
	}
	return (1);
}
