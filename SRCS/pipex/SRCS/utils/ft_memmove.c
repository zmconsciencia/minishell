/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:18:05 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/06 11:23:42 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

//move o que esta no bloco src para o bloco dest.
//foi necesseario criar tmpdst que aponta para o mesmo 
//sitio onde aponta dst original, por este ser void.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmpdest;
	char	*tmpsrc;
	size_t	i;

	tmpdest = (char *)dest;
	tmpsrc = (char *)src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			tmpdest[i - 1] = tmpsrc[i - 1];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			tmpdest[i] = tmpsrc[i];
	}
	return (dest);
}

/* int	main(void)
{
	char	src[] = "hello";
	char	dest[] = "blabla";

	printf("%s\n", (char *)ft_memmove(dest, src, 4));
	return (0);
}
 */
