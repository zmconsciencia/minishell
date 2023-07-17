/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:54:05 by jabecass          #+#    #+#             */
/*   Updated: 2023/07/17 18:49:26 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i += 1;
	return ((i));
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*ret;
	size_t	i;

	ret = malloc(ft_strlen_gnl(str1) + ft_strlen_gnl(str2) + 1);
	if (!ret)
		return (NULL);
	if (!ret)
		return (NULL);
	i = -1;
	while (str1 && str1[++i])
		ret[i] = str1[i];
	i += (!str1);
	while (*str2)
	{
		ret[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	ret[i] = 0;
	free (str1);
	return (ret);
}

int	clearstack(char *stack)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (stack[++i])
	{
		if (stack[i] == '\n')
		{
			stack[i++] = 0;
			j = 0;
			break ;
		}
		stack[i] = 0;
	}
	if (!j)
	{
		while (stack[i])
		{
			stack[j++] = stack[i];
			stack[i++] = 0;
		}
	}
	return (j);
}
