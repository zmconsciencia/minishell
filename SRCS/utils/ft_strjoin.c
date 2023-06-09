/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:33:51 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/09 12:34:31 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//junta duas strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s3start;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == 0)
		return (0);
	s3start = s3;
	while (*s1)
	{
		*s3 = *s1;
		s1++;
		s3++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	*s3 = 0;
	return (s3start);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("bruno", "levi"));
// }