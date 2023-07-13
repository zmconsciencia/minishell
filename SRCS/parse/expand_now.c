/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_now.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:14:58 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/13 13:14:59 by bde-seic         ###   ########.fr       */
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
	var_name = malloc(sizeof(char) * (i - s) + 1);
	while (++s < i && g_line[s] != '\"')
		var_name[v++] = g_line[s];
	var_name[v] = '=';
	var_name[++v] = 0;
	var = expanded_dollar(var_name);
	free(var_name);
	return (var);
}

int	get_e(char *g_line, int s)
{
	int	e;

	e = s;
	if (g_line[e + 1] != '?')
		while ((is_alpha_num(g_line[++e]) || g_line[e] == '_') \
			&& g_line[e] != ' ')
			;
	else
		e += 2;
	return (e);
}

char	*insert_var(char *g_line, int s, char *var)
{
	int		i;
	int		v;
	int		e;
	char	*joined;

	e = get_e(g_line, s);
	joined = malloc(sizeof(char) * (ft_strlen(g_line) - (e - s)) \
	+ ft_strlen(var) + 1);
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < s)
		joined[i] = g_line[i];
	v = 0;
	if (var[0])
		while (var[v])
			joined[i++] = var[v++];
	while (g_line[e])
		joined[i++] = g_line[e++];
	joined[i] = 0;
	free(g_line);
	return (joined);
}

char	*do_it_do_it(char *g_line, int i)
{
	char	*var;

	var = 0;
	if (g_line[i + 1] == '?')
		var = ft_itoa(meta()->exitcode);
	else
		var = get_var(g_line, i);
	if (var)
		g_line = insert_var(g_line, i, var);
	free(var);
	return (g_line);
}

char	*expand_now(char *g_line, char a)
{
	int		i;

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
				g_line = do_it_do_it(g_line, i);
		}
		if (!g_line[i])
			break ;
	}
	return (g_line);
}
