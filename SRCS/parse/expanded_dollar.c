/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:10:59 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/10 13:28:07 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// t_meta	*meta(void)
// {
// 	static t_meta	meta;

// 	return (&meta);
// }

// int	check_true(char	*scroll, char *no_dollar_equal)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = ft_strlen(no_dollar_equal);
// 	while (i < size && no_dollar_equal[i] && scroll[i] && \
// 		scroll[i] == no_dollar_equal[i])
// 		i++;
// 	if (i == size)
// 		return (1);
// 	return (0);
// }

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
	char	*no_dollar_equal;

	i = 0;
	no_dollar_equal = ft_strjoin(remove_dollar(input), "=");
	while (meta()->envp[i])
	{
		if (ft_strncmp(meta()->envp[i], no_dollar_equal, \
			ft_strlen(no_dollar_equal)))
			return (trim_input(meta()->envp[i], input));
		i++;
	}
	free(no_dollar_equal);
	return (0); // fazer free ao output
}

// int	main(int ac, char **av, char **envp)
// {
// 	meta()->envp = envp;
// 	printf("%s\n", expanded_dollar("$USERola"));
// }