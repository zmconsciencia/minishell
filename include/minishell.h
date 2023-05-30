/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/30 11:18:21 by bde-seic         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pot{
	char	*path_program;
	char	*program;
	char	**flags;
	char	**envp;
}	t_pot;

typedef struct s_red{
	int		fd_in;
	int		fd_out;
	int		fd[2];
	int		here_doc;
	char	*limiter;
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

//execute
void		execute(void);
void		clear_last(void);
void		run_heredoc(char *file_name, t_program *node);

//handle
void		sighandler(int signum);
void		sighandler2(int signum);

//utils
int			count_strings(char **strings);
int			desired_len(char *str, char op);
void		free_lines(char	**lines);
int			ft_is_space(char c);
void		ft_putstr_fd(char *s, int fd);
int			ft_return_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strnstr(char *big, char *little, size_t n);
t_program	*get_curr_prog(int id);
char		*get_filename(char *token);
char		*get_op(char *token);
int			is_alpha_num(char c);
char		*new_strjoin(char op, char const *s2);
void		print_program(t_program *node);

//parse
int			check_syntax(char *g_line);
char		*expanded_dollar(char *input);
char		*expand_now(char *g_line, char a);
void		fill_pot(char *token, t_program *node);
void		fill_red(char *token, t_program *node);
void		parse_nodes(char **tokens, int node_id);
char		*treat_and_replace(char *g_line);
char		*treat_quotes(char *token);
void		treat_infiles(char *file_name, t_program *node);
void		treat_outfiles(char *file_name, t_program *node);
void		treat_append(char *file_name, t_program *node);

//builtins
int			check_builtin(t_program *curr);
int			is_builtin(char	*builtin, char *quoted_line);
int			my_cd(char **path);
int			my_echo(char **flags);
int			my_env(void);
// int		my_export(char *quoted_line);
int			my_pwd(char	**flags);
// int		my_unset(char *quoted_line);

//gnl
char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *str);
char		*ft_strjoin_gnl(char *str1, char *str2);
int			clearstack(char *stack);

//pipex
void		pipex(t_program *program);
char		**get_path(char **envp);
char		*trim_path(char *env_var);
char		*check_access(char **paths, char *arg);
char		*join_path(char *path, char *arg);
void		fill_list(t_program **list, int argc, char **argv, char **envp);
void		free_my_list(t_program *list);

#endif