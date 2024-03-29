/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:36:53 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/12 16:27:20 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_non_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+'
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	sai_daqui(void)
{
	clear_last();
	free_lines(meta()->envp);
	printf("exit\n");
	exit(meta()->exitcode);
}

void	my_exit(char **flags)
{
	long long	code;

	code = 0;
	meta()->exitcode = 0;
	if (count_strings(flags) > 2)
	{
		ft_putstr_fd(" too many arguments\n", 2);
		meta()->exitcode = 1;
	}
	else
	{
		if (count_strings(flags) == 2 && has_non_numeric(flags[1]))
		{
			ft_putstr_fd(" numeric argument required\n", 2);
			meta()->exitcode = 2;
		}
		else if (count_strings(flags) == 2)
		{
			code = ft_atoi(flags[1]);
			meta()->exitcode = code;
		}
	}
	sai_daqui();
}
