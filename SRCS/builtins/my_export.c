/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:55 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/04 01:58:40 by jabecass         ###   ########.fr       */
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

void	print_export()
{
	char	**env;
	int		i;
	
	i = 0;
	env = meta()->envp;
	while(env[i])
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
}

void	add_var(char *str)
{
	char	**env;
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = meta()->envp;
	new_env = malloc(sizeof(char **) * count_strings(meta()->envp) + 2);
	while(env[i])
	{
		new_env[j] = malloc(sizeof(char) * (strlen(env[i]) + 1));
		strcpy(new_env[j], env[i]);
		j++;
		i++;
	}
	new_env[j] = malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(new_env[j++], str);
	new_env[j] = '\0';
	meta()->envp = new_env;
}

int	my_export(char **flags)
{
	if (count_strings(flags) == 1)
		print_export();
	else if (count_strings(flags) == 2)
		add_var(flags[1]);
	return (1);
}

// falta mudar strcpy para funcoes nossas, falta implementar que a variavel so passa para o env
// quando depois de ser dada valor (export MY_VAR=BIA) seja sourced com (export MY_VAR), e falta
// implementar para que e nova variavel criada seja expandida - possivel ser dentro do expanded dollar

// como esta a correr agora:
// minishell> export MY_VAR=BIA
// minishell> env | grep BIA
// MY_VAR=BIA
// minishell> echo $MY_VAR
// MY_VAR