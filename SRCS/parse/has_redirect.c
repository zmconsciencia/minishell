/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:36:44 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/27 20:53:40 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_redirect(char *token)
{
	int	i;

	i = -1;
	while (token[++i])
		if (token[i] == '<' || token[i] == '>')
			return (1);
	return (0);
}
