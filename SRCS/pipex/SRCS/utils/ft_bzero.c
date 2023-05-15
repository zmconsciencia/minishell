/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:40:41 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/06 10:13:48 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

//transforma os elementos do bloco de memoria em 0, ate ao size.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int main(void)
{
    char str[] = "hello world";
    int i;

    i = ft_strlen(str);
    ft_bzero(str, 6);
    write(1, str, i);
}
*/