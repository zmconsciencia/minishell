/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:23:29 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 10:36:06 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*new_strjoin(char op, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 1;
	s3 = (char *)malloc(sizeof(char) * (1 + ft_strlen(s2) + 1));
	if (s3 == 0)
		return (0);
	s3[0] = op;
	while (s2[i])
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = 0;
	return (s3);
}
