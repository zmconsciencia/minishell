/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/04/24 17:41:46 by jabecass         ###   ########.fr       */
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
	int					pipe_idx;
	int					type;
	char				*program;
	char				**flags;
	char				*g_line;
	int					fd[2];
	struct s_program	*next;
}	t_program;

void	sighandler(int signum);
void	sighandler2(int signum);
char	**ft_split(char const *s, char c);
t_program	*program(void);

#endif