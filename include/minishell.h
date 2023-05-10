/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/10 11:52:25 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
	int		fd_out;
	int		fd[2];
}	t_red;

typedef struct s_program{
	int					node_id;
	struct s_pot		pot;
	struct s_red		red;
	struct s_program	*next;
}	t_program;

typedef struct s_meta{
	struct s_program	*head;
	struct s_program	*tail;
}	t_meta;

t_program	*program(void);

//handle
void		sighandler(int signum);
void		sighandler2(int signum);

//utils
int			count_strings(char **strings);
void		free_lines(char	**lines);
int			ft_is_space(char c);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_program	*get_curr_prog(int id);
char		*new_strjoin(char op, char const *s2);

//parse
int			check_syntax(char *g_line);
int			desired_len(char *str, char op);
void		fill_dollar(char *token, int id);
void		fill_pot(char *token, int id);
void		fill_red(char *token, int id);
void		fill_red2(char *token, int node_id);
char		*get_filename(char *token);
char		*get_op(char *token);
int			has_redirect(char *token);
void		parse_nodes(char **tokens, int node_id);
char		*treat_redirect(char *token, int node_id);

//builtins
int			check_builtin(char	**quoted_line);
int			is_builtin(char	*builtin, char *quoted_line);
// int		my_cd(char **quoted_line);
int			my_echo(char **quoted_line);
// int		my_env(char **quoted_line);
// int		my_export(char *quoted_line);
int			my_pwd(char **quoted_line);
// int		my_unset(char *quoted_line);

//gnl
size_t		ft_strlen_gnl(const char *str);
char		*ft_strjoin_gnl(char *str1, char *str2);
int			clearstack(char *stack);
char		*get_next_line(int fd);

#endif