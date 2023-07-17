/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:40:04 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 18:50:40 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*add_three(char *g_line, int i)
{
	char	*new;
	int		y;
	int		x;

	y = 0;
	x = 0;
	new = malloc(sizeof(char) * ft_strlen(g_line) + 2);
	if (!new)
		return (NULL);
	while (y < i)
		new[x++] = g_line[y++];
	new[x] = 3;
	x++;
	while (g_line[y])
		new[x++] = g_line[y++];
	new[x] = 0;
	free(g_line);
	return (new);
}

int	cut_lines_treat2(char *g_line, int i)
{
	while (g_line[i] == '<' || g_line[i] == '>')
	{
		if (g_line[i] == '<')
			g_line[i] = 5;
		else if (g_line[i] == '>')
			g_line[i] = 6;
		i++;
		if (!g_line[i])
			i--;
	}
	if (g_line[i] == ' ')
		while (ft_is_space(g_line[++i]) && \
			(g_line[i + 1] != '<' && g_line[i + 1] != '>'))
			;
	if (g_line[i] == '\"' || g_line[i] == '\'')
		i--;
	return (i);
}

char	return_nbr(char c, int flag)
{
	if (c == '|' && !flag)
		return (2);
	if (c == ' ' && !flag)
		return (3);
	if (c == '$')
		return (4);
	else
		return (c);
}

char	*treat_and_replace(char *g_line)
{
	int	i;

	i = -1;
	while (g_line[++i])
	{
		g_line[i] = return_nbr(g_line[i], 0);
		if (g_line[i] == '\"')
		{
			while (g_line[++i] != '\"' && g_line[i] != 0)
			{
				g_line[i] = return_nbr(g_line[i], 1);
				if ((i == ft_strlen(g_line) - 1) && (g_line[i] != '\"'))
					break ;
			}
		}
		if (g_line[i] == '\'')
			while (g_line[++i] != '\'' && g_line[i] != 0)
				;
		if (g_line[i] == '<' || g_line[i] == '>')
		{
			g_line = add_three(g_line, i++);
			i = cut_lines_treat2(g_line, i);
		}
	}
	return (expand_now(g_line, 4));
}
