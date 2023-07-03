/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/03 15:30:03 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	red_syntax(char	*g_line)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (g_line[i])
	{
		if (g_line[i] == '<')
		{
			if (g_line[i + 1] == '>')
				return (0);
			while (g_line[i++] == '<')
				counter++;
			if (counter > 2)
				return (0);
		}
		else if (g_line[i] == '>')
		{
			if (g_line[i + 1] == '<')
				return (0);
			while (g_line[i++] == '>')
				counter++;
			if (counter > 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int	pipe_syntax(char *g_line)
{
	int	i;

	i = 0;
	while (g_line[i])
	{
		if (g_line[i] == '|')
			if (g_line[++i] == '|')
				return (0);
		i++;
	}
	return (1);
}

int	check_syntax(char *g_line)
{
	int	sum;

	sum = pipe_syntax(g_line) + red_syntax(g_line);
	if (sum != 2 || g_line[0] == '|' || g_line[ft_strlen(g_line) - 1] == '|')
	{
		printf("Syntax error. \n");
		meta()->exitcode = 2;
		return (0);
	}
	return (1);
}
