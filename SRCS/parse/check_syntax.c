/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/05/03 19:44:41 by jabecass         ###   ########.fr       */
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
			while (g_line[i++] == '<')
				counter++;
			if (counter > 2)
				return (0);
		}
		else if (g_line[i] == '>')
		{
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
	if (sum != 2)
	{
		printf("Syntax error. \n");
		return (0);
	}
	return (1);
}