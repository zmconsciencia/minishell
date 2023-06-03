/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/03 23:23:23 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int	var_len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0' || str[i] != '=')
// 		i++;
// 	return (i);
// }

// char	*get_var_name(char *str)
// {
// 	char	*var;
// 	int		len;
// 	int		i;
// 	int		j;

// 	len = var_len(str);
// 	var = malloc(sizeof(char) * len + 1);
// 	i = 0;
// 	j = 0;
// 	while (str[i] != '\0' || str[i] != '=')
// 	{
// 		var[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	var[i] = '\0';
// 	return (var);
// }

// char	*get_var_value(char *str)
// {
// 	char	*value;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	value = malloc(sizeof(char) * (ft_strlen(str) - var_len(str)));
// 	while (str[i] != '=')
// 		i++;
// 	i++;
// 	while (str[i])
// 	{
// 		value[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	value[i] = '\0';
// 	return (value);
// }

int	my_export(char **flags)
{
	int		i;
	char	**env;
	
	i = 0;
	env = meta()->envp;
	if (count_strings(flags) == 1)
	{
		while(env[i])
		{
			printf("declare -x %s\n", env[i]);
			i++;
		}
	}
	return (1);
}
