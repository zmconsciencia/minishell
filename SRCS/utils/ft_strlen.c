/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:00:06 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/17 18:52:01 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//tamanho da string.
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	n = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (i < ft_strlen(s1))
		new[n++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		new[n++] = s2[i++];
	new[n] = '\0';
	return (new);
}
