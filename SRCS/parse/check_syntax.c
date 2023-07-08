/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/08 22:34:02 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	red_syntax(char	*g_line)
{
	int	i;
	int	j;
	int c = 1;

	i = 0;
	j = 0;
	while (g_line[i])
	{
		if (g_line[i] == '\"')
			while (g_line[++i] && g_line[i] != '\"')
				;
		if (g_line[i] == 5 && g_line[i + 1] == 6)
			meta()->synerr = 1;
		else if (g_line[i] == 6 && g_line[i + 1] == 5)
			meta()->synerr = 1;
		i++;
	}
	i = 0;
	while (g_line[i++])
	{
		if (g_line[i] == '\"')
			while (g_line[++i] && g_line[i] != '\"')
				;
		if (g_line[i] == 5 || g_line[i] == 6)
		{
			j = i;
			c = 0;
			while (g_line[j++])
				if (is_alpha_num(g_line[j]))
					c = 1;	
		}
	}
	if (c == 0)
		meta()->synerr = 1;
}

static void	pipe_syntax(char *g_line)
{
	int	i;

	i = 0;
	if (g_line[0] == 2 || g_line[ft_strlen(g_line) - 1] == 2)
		meta()->synerr = 1;
	while (g_line[i])
	{
		if (g_line[i] == '\"')
			while (g_line[++i] && g_line[i] != '\"')
				;
		if (g_line[i] == 2)
			if (g_line[++i] == 2)
				meta()->synerr = 1;
		i++;
	}
}

int	check_syntax(char *g_line)
{
	meta()->synerr = 0;
	pipe_syntax(g_line);
	red_syntax(g_line);
	if (meta()->synerr)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `\n", 2);
		meta()->exitcode = 2;
		return (0);
	}
	else
		return (1);
}
