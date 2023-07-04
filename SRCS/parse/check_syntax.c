/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/04 15:00:17 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	red_syntax(char	*g_line)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (g_line[i])
	{
		if (g_line[i] == '<' && g_line[i + 1] == '>')
			meta()->synerr = 1;
		else if (g_line[i] == '>' && g_line[i + 1] == '<')
			meta()->synerr = 1;
		i++;
	}
}

static void	pipe_syntax(char *g_line)
{
	int	i;

	i = 0;
	if (g_line[0] == 2 || g_line[ft_strlen(g_line) - 1] == 2)
		meta()->synerr = 1;
	while (g_line[i])
	{
		if (g_line[i] == 2)
			if (g_line[++i] == 2)
				meta()->synerr = 1;
		i++;
	}
}

int	check_syntax(char *g_line)
{
	red_syntax(g_line);
	pipe_syntax(g_line);
	if (meta()->synerr)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `\n", 2);
		meta()->exitcode = 2;
		return (0);
	}
	else
		return (1);
}
