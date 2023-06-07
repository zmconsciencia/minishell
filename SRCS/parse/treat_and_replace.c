/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:40:04 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/07 10:35:09 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_var(char *g_line, int s)
{
	int		i;
	int		v;
	char	*var;
	char	*var_name;

	var = 0;
	v = 0;
	var_name = 0;
	i = s;
	while (ft_isprint(g_line[++i]) && g_line[i] != ' ')
		;
	var_name = malloc(sizeof(char) * (i - s) + 2);
	while (++s < i && g_line[s] != '\"')
		var_name[v++] = g_line[s];
	var_name[v] = '=';
	var_name[++v] = 0;
	var = expanded_dollar(var_name);
	free(var_name);
	return (var);
}

char	*insert_var(char *g_line, int s, char *var)
{
	int		i;
	int		v;
	int		e;
	char	*joined;

	e = s;
	while (ft_isprint(g_line[++e]) && g_line[e] != ' ')
		e++;
	joined = malloc(sizeof(char) * (ft_strlen(g_line) - (e - s)) \
	+ ft_strlen(var) + 1);
	i = -1;
	while (++i < s)
		joined[i] = g_line[i];
	v = 0;
	while (var[v])
		joined[i++] = var[v++];
	while (g_line[e])
		joined[i++] = g_line[e++];
	joined[i] = 0;
	free(g_line);
	return (joined);
}

char	*expand_now(char *g_line, char a)
{
	int		i;
	char	*var;

	i = -1;
	while (g_line[++i])
	{
		while (g_line[i] != a && g_line[i])
			i++;
		if (g_line[i] == a)
		{
			if (g_line[i + 1] == ' ' || g_line[i + 1] == '\"' || !g_line[i + 1])
				g_line[i] = '$';
			else
			{
				var = get_var(g_line, i);
				if (var)
					g_line = insert_var(g_line, i, var);
				free(var);
			}
		}
		else if (!g_line[i])
			break ;
	}
	return (g_line);
}

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

char	*treat_and_replace(char *g_line)
{
	int	i;

	i = -1;
	while (g_line[++i])
	{
		if (g_line[i] == '|')
			g_line[i] = 2;
		if (g_line[i] == ' ')
			g_line[i] = 3;
		if (g_line[i] == '$')
			g_line[i] = 4;
		if (g_line[i] == '\"')
			while (g_line[++i] != '\"' && g_line[i] != 0/*  && g_line[i + 1] != '|' */) // -> corrigir caso nao tenha fim de aspas
				if (g_line[i] == '$')
					g_line[i] = 4;
		if (g_line[i] == '\'')
			while (g_line[++i] != '\'' && g_line[i] != 0)
				;
		if (g_line[i] == '<' || g_line[i] == '>')
		{
			g_line = add_three(g_line, i);
			while (g_line[++i] == '<' || g_line[i] == '>')
				i++;
			while (ft_is_space(g_line[++i]) && \
				(g_line[i + 1] != '<' && g_line[i + 1] != '>'))
				;
		}
	}
	g_line = expand_now(g_line, 4);
	return (g_line);
}
