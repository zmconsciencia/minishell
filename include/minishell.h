/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/24 14:04:55 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUILTIN 1
# define OPERATOR 2
# define PIPE 3
# define FILENAME 4
# define PROGRAM 5
# define FLAG 6
# define OTHER 7

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>

typedef struct s_program{
	int					type;
	char				*file;
	char				character;
	char				*program;
	char				**flags;
	int					start;
	int					i;
	struct s_program	*next;
	struct s_program	*prev;
}	t_program;

void	sighandler(int signum);
void	sighandler2(int signum);
char	**ft_split(char const *s, char c);

#endif