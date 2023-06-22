/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:14:03 by bde-seic          #+#    #+#             */
/*   Updated: 2023/06/22 14:34:32 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_lines(char	**lines)
{
	int	i;

	i = 0;
	if (lines)
	{
		while (lines[i])
			free(lines[i++]);
		free(lines);
	}
}
