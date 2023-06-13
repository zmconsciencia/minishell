/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:09:29 by jabecass          #+#    #+#             */
/*   Updated: 2023/06/13 12:05:05 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	flag_parse(char *flag, char type)
{
	int	i;

	i = 1;
	if (flag[0] == '-')
	{
		while (flag[i])
		{
			if (flag[i] != type)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

char	**sort_alpha(char **arr, int size)
{
	int		i;
	int		swapped;
	char	*temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strncmp(arr[i], arr[i + 1], ft_strlen(arr[i])) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		size--;
	}
	return (arr);
}

char	*add_quotes(char *str)
{
	size_t		i;
	size_t		j;
	char		*new;
	int			flag;

	i = -1;
	j = 0;
	flag = 0;
	new = malloc(sizeof(char) * ft_strlen(str) + 3);
	while (++i < (ft_strlen(str) + 3))
	{
		new[j] = str[i];
		if (str[i] == '=' && flag == 0)
		{
			new[j + 1] = '"';
			j++;
			flag = 1;
		}
		if (i == ft_strlen(str))
		{
			new[j] = '"';
			j++;
			break ;
		}
		j++;
	}
	new[j] = '\0';
	return (new);
}
