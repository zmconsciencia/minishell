/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:03:08 by bde-seic          #+#    #+#             */
/*   Updated: 2022/10/20 18:42:34 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_calloc(size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = -1;
	if (size != 0)
		while (++i < size)
			((char *)ptr)[i] = 0;
	return (ptr);
}

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

char	**stringcount(char const *s, char c)
{
	char	**string;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	string = (char **)malloc(sizeof (char *) * (count + 1));
	if (!string)
		return (0);
	string[count] = 0;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		num;
	int		i;
	int		start;

	num = 0;
	i = 0;
	string = stringcount(s, c);
	if (!string)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			string[num] = (char *)ft_calloc(i - start + 1);
			ft_memmove(string[num], &s[start], i - start);
			num++;
		}
	}
	return (string);
}
