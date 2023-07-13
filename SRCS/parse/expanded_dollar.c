/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:10:59 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/23 11:30:20 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*trim_input(char *scroll, char *input)
{
	int		i;
	int		j;
	char	*trimed;

	i = ft_strlen(input);
	j = 0;
	trimed = malloc(sizeof(char) * (ft_strlen(scroll) - i + 1));
	while (scroll[i])
		trimed[j++] = scroll[i++];
	trimed[j] = '\0';
	return (trimed);
}

char	*remove_dollar(char *input)
{
	int		i;
	int		j;
	char	*no_dollar;

	i = ft_strlen(input);
	j = 0;
	no_dollar = malloc(sizeof(char) * i);
	no_dollar[i - 1] = 0;
	i = 1;
	while (input[i])
		no_dollar[j++] = input[i++];
	return (no_dollar);
}

char	*expanded_dollar(char *input)
{
	int		i;

	i = 0;
	while (meta()->envp[i])
	{
		if (!ft_strncmp(meta()->envp[i], input, \
			ft_strlen(input)))
			return (trim_input(meta()->envp[i], input));
		i++;
	}
	return (ft_strdup(""));
}

// int	main(int ac, char **av, char **envp)
// {
// 	meta()->envp = envp;
// 	printf("%s\n", expanded_dollar("$LESS"));
// }