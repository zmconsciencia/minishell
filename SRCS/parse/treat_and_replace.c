/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:40:04 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/10 15:14:47 by jabecass         ###   ########.fr       */
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
char	*cut_lines_treat2(char *g_line, int i)
{
	if (g_line[i] == '<' || g_line[i] == '>')
	{
		g_line = add_three(g_line, i++);
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
	}
	return (g_line);
}

char	*cut_lines_treat(char *g_line, int i)
{
	if (g_line[i] == '|')
		g_line[i] = 2;
	if (g_line[i] == ' ')
		g_line[i] = 3;
	if (g_line[i] == '$')
		g_line[i] = 4;
	if (g_line[i] == '\"')
	{
		while (g_line[++i] != '\"' && g_line[i] != 0)
		{
			if (g_line[i] == '$')
				g_line[i] = 4;
			if ((i == ft_strlen(g_line) - 1) && (g_line[i] != '\"'))
				break ;
		}
	}
	if (g_line[i] == '\'')
		while (g_line[++i] != '\'' && g_line[i] != 0)
			;
	return (g_line);
}

char	return_nbr(char c)
{
	if (c == '|')
		return (2);
	else if (c == ' ')
		return (3);
	else if (c == '$')
		return (4);
	else if (c == '<')
		return (5);
	else if (c == '>')
		return (6);
	else
		return (c);
}

char	*treat_and_replace(char *g_line)
{
	int	i;

	i = -1;
	while (g_line[++i])
	{
		g_line[i] = return_nbr(g_line[i]);
		// if (g_line[i] == '|')
		// 	g_line[i] = 2;
		// if (g_line[i] == ' ')
		// 	g_line[i] = 3;
		// if (g_line[i] == '$')
		// 	g_line[i] = 4;
		if (g_line[i] == '\"')
			while (g_line[++i] != '\"' && g_line[i] != 0)
			{
				g_line[i] = return_nbr(g_line[i]);
				if ((i == ft_strlen(g_line) - 1) && (g_line[i] != '\"'))
					break ;
			}
		if (g_line[i] == '\'')
			while (g_line[++i] != '\'' && g_line[i] != 0)
				;
		if (g_line[i] == '<' || g_line[i] == '>')
		{
			g_line = add_three(g_line, i++); //aqui
			while (g_line[i] == '<' || g_line[i] == '>')
			{
				g_line[i] = return_nbr(g_line[i]);
				i++;
				if (!g_line[i]) //aqui
					i--;
			}
			if (g_line[i] == ' ')
				while (ft_is_space(g_line[++i]) && \
					(g_line[i + 1] != '<' && g_line[i + 1] != '>'))
					;
			if (g_line[i] == '\"' || g_line[i] == '\'')
				i--;
		}
	}
	g_line = expand_now(g_line, 4);
	return (g_line);
}


// char	*treat_and_replace(char *g_line)
// {
// 	int	i;

// 	i = -1;
// 	while (g_line[++i])
// 	{
// 		g_line = cut_lines_treat(g_line, i);
// 		// g_line = cut_lines_treat2(g_line, i);
// 		if (g_line[i] == '<' || g_line[i] == '>')
// 		{
// 			g_line = add_three(g_line, i++);
// 			while (g_line[i] == '<' || g_line[i] == '>')
// 			{
// 				if (g_line[i] == '<')
// 					g_line[i] = 5;
// 				else if (g_line[i] == '>')
// 					g_line[i] = 6;
// 				i++;
// 				if (!g_line[i])
// 					i--;
// 			}
// 			if (g_line[i] == ' ')
// 				while (ft_is_space(g_line[++i]) && \
// 					(g_line[i + 1] != '<' && g_line[i + 1] != '>'))
// 					;
// 			if (g_line[i] == '\"' || g_line[i] == '\'')
// 				i--;
// 		}
// 	}
// 	g_line = expand_now(g_line, 4);
// 	return (g_line);
// }

/* ---------- ORIGINAL NAO MEXER ----------- */
// char	*treat_and_replace(char *g_line)
// {
// 	int	i;

// i = -1;
// while (g_line[++i])
// {
// 	if (g_line[i] == '|')
// 		g_line[i] = 2;
// 	if (g_line[i] == ' ')
// 		g_line[i] = 3;
// 	if (g_line[i] == '$')
// 		g_line[i] = 4;
// 	if (g_line[i] == '\"')
// 		while (g_line[++i] != '\"' && g_line[i] != 0)
// 		{
// 			if (g_line[i] == '$')
// 				g_line[i] = 4;
// 			if ((i == ft_strlen(g_line) - 1) && (g_line[i] != '\"'))
// 				break ;
// 		}
// 	if (g_line[i] == '\'')
// 		while (g_line[++i] != '\'' && g_line[i] != 0)
// 			;
// 	if (g_line[i] == '<' || g_line[i] == '>')
// 	{
// 		g_line = add_three(g_line, i++); //aqui
// 		while (g_line[i] == '<' || g_line[i] == '>')
// 		{
// 			if (g_line[i] == '<')
// 				g_line[i] = 5;
// 			else if (g_line[i] == '>')
// 				g_line[i] = 6;
// 			i++;
// 			if (!g_line[i]) //aqui
// 				i--;
// 		}
// 		if (g_line[i] == ' ')
// 			while (ft_is_space(g_line[++i]) && \
// 				(g_line[i + 1] != '<' && g_line[i + 1] != '>'))
// 				;
// 		if (g_line[i] == '\"' || g_line[i] == '\'')
// 			i--;
// 	}
// }
// 	g_line = expand_now(g_line, 4);
// 	return (g_line);
// }
