// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   treat_and_replace_cp.c                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/04 09:40:04 by bde-seic          #+#    #+#             */
// /*   Updated: 2023/05/04 10:06:42 by bde-seic         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/minishell.h"

// char	*add_three(char *g_line, int i)
// {
// 	char	*new;
// 	int		y;
// 	int		x;

// 	y = 0;
// 	x = 0;
// 	new = malloc(sizeof(char) * ft_strlen(g_line) + 2);
// 	while (y <= i)
// 		new[x++] = g_line[y++];
// 	new[++x] = 3;
// 	while (g_line[y])
// 		new[x++] = g_line[y++];
// 	free(g_line);
// 	return (new);
// }

// char	*treat_and_replace_cp(char *g_line)
// {
// 	int	i;

// 	i = -1;
// 	while (g_line[++i])
// 	{
// 		if (g_line[i] == '|')
// 			g_line[i] = 2;
// 		if (g_line[i] == ' ')
// 			g_line[i] = 3;
// 		if (g_line[i] == '\"')
// 			while (g_line[++i] != '\"' && g_line[i] != 0)
// 				i++;
// 		if (g_line[i] == '\'')
// 			while (g_line[++i] != '\'' && g_line[i] != 0)
// 				i++;
// 		if (g_line[i] == '<' || g_line[i] == '>')
// 		{
// 			g_line = add_three(g_line, i);
// 			while (ft_is_space(g_line[++i]))
// 				;
// 			treat_and_replace_cp(g_line);
// 		}
// 	}
// 	return (g_line);
// }
