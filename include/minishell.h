/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/11 14:11:14 by bde-seic         ###   ########.fr       */
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
# include <fcntl.h>

typedef struct s_pot{
	char	*program;
	char	**flags;
	char	**envp;
}	t_pot;

typedef struct s_red{
	int		fd_in;
	int		fd[2];
}	t_red;

typedef struct s_program{
	int					program_id;
	struct s_pot		pot;
	struct s_red		red;
	struct s_program	*next;
}	t_program;

typedef struct s_meta{
	char				**envp;
	struct s_program	*head;
	struct s_program	*tail;
}	t_meta;

t_meta		*meta(void);

//handle
void		sighandler(int signum);
void		sighandler2(int signum);

//utils
int			count_strings(char **strings);
void		free_lines(char	**lines);
int			ft_is_space(char c);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strnstr(char *big, char *little, size_t n);
t_program	*get_curr_prog(int id);
int			is_alpha_num(char c);
char		*new_strjoin(char op, char const *s2);

//parse
int			check_syntax(char *g_line);
char		*expanded_dollar(char *input);
void		fill_dollar(char *token, int id);
void		fill_pot(char *token, int id);
void		fill_red(char *token, int id);
void		fill_red2(char *token, int node_id);
int			has_redirect(char *token);
void		parse_nodes(char **tokens, int node_id);
void		treat_redirect(char *token, int node_id);
char		*treat_and_replace(char *g_line);
char		*treat_quotes(char *token);

//builtins
int			check_builtin(char	**quoted_line);
int			is_builtin(char	*builtin, char *quoted_line);
// int		my_cd(char **quoted_line);
int			my_echo(char **quoted_line);
// int		my_env(char **quoted_line);
// int		my_export(char *quoted_line);
int			my_pwd(char **quoted_line);
// int		my_unset(char *quoted_line);

#endif