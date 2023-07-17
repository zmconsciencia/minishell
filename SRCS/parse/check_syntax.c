/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/17 18:45:41 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_in_quotes(char *str, int i)
{
	int		j;
	char	c;

	j = 0;
	c = 0;
	while (j < i)
	{
		if ((j == 0 || !count_back(str, j, '\\')) && \
		(str[j] == '"' || str[j] == '\''))
		{
			if (c == str[j])
				c = 0;
			else if (c == 0)
				c = str[j];
		}
		j++;
	}
	return (c);
}

static void	red_syntax(char	*g_line)
{
	int	i;

	i = 0;
	while (g_line[i])
	{
		if (!is_in_quotes(g_line, i) && g_line[i] == 5 && g_line[i + 1] == 6)
			meta()->synerr = 1;
		if (!is_in_quotes(g_line, i) && g_line[i] == 6 && g_line[i + 1] == 5)
			meta()->synerr = 1;
		if (!is_in_quotes(g_line, i) && g_line[i] == 5)
			if (g_line[++i] == 5 && g_line[++i] == 5)
				meta()->synerr = 1;
		if (!is_in_quotes(g_line, i) && g_line[i] == 6)
			if (g_line[++i] == 6 && g_line[++i] == 6)
				meta()->synerr = 1;
		i++;
	}
}

static void	red_syntax2(char *g_line)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 1;
	while (g_line[i++])
	{
		if (!is_in_quotes(g_line, i) && (g_line[i] == 5 || g_line[i] == 6))
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
		if (!is_in_quotes(g_line, i) && g_line[i] == 2)
			if (g_line[++i] == 2)
				meta()->synerr = 1;
		i++;
	}
}

int	check_syntax(char *g_line)
{
	meta()->synerr = 0;
	if (!g_line[0])
		return (1);
	pipe_syntax(g_line);
	red_syntax(g_line);
	red_syntax2(g_line);
	if (meta()->synerr)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `\n", 2);
		meta()->exitcode = 2;
		return (0);
	}
	else
		return (1);
}
