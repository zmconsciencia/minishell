/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/03 07:21:18 by bde-seic         ###   ########.fr       */
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

typedef struct s_pot{
	char	*program;
	char	**flags;
	char	**envp;
}	t_pot;

typedef struct s_red{
	char	*operator;
	char	*file_name;
}	t_red;

typedef struct s_program{
	int					node_id;
	struct s_pot		pot;
	struct s_red		red;
	int					fd[2];
	struct s_program	*next;
}	t_program;

t_program	*program(void);

//handle
void	sighandler(int signum);
void	sighandler2(int signum);

//utils
int			count_strings(char **strings);
char		**ft_split(char const *s, char c);
void		free_lines(char	**lines);
int			ft_is_space(char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_program	*get_curr_prog(int id);

//parse
void	fill_dollar(char *token, int id);
void	fill_pot(char *token, int id);
void	fill_red(char *token, char *nxt_token, int id);
int		has_redirect(char *token);
void	parse_nodes(char **tokens, int node_id);

//builtins
int		check_builtin(char	**quoted_line);
int		is_builtin(char	*builtin, char *quoted_line);
// int		my_cd(char **quoted_line);
int		my_echo(char **quoted_line);
// int		my_env(char **quoted_line);
// int		my_export(char *quoted_line);
int		my_pwd(char **quoted_line);
// int		my_unset(char *quoted_line);

#endif