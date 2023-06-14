/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:50:51 by jabecass          #+#    #+#             */
/*   Updated: 2023/06/14 14:42:19 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	desired_len(char *str, char op)
{
	int	i;

	i = 0;
	while (str[i] == op || ft_is_space(str[i]))
		i++;
	return (ft_strlen(str) - i);
}

char	*get_filename(char *token)
{
	char	*file_name;
	int		i;
	int		j;

	i = 1;
	j = 0;
	file_name = malloc(sizeof(char) * desired_len(token, token[0]) + 1);
	while (ft_is_space(token[i]) || token[i] == token[0])
		i++;
	while ((token[i] != '\0') || ft_is_space(token[i]))
		file_name[j++] = token[i++];
	file_name[j] = '\0';
	return (file_name);
}

char	*get_op(char *token)
{
	int		i;
	int		j;
	char	*op;

	i = 1;
	j = 0;
	while (token[i] == token[0])
		i++;
	op = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		op[j] = token[0];
		j++;
	}
	op[j] = '\0';
	return (op);
}
