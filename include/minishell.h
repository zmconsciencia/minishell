/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:31:50 by bde-seic          #+#    #+#             */
/*   Updated: 2023/07/12 16:33:31 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

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
	int					exec;
	int					hc;
	int					synerr;
	int					exitcode;
	char				**envp;
	struct s_program	*head;
	struct s_program	*tail;
}	t_meta;

t_meta		*meta(void);

//execute
void		execute(void);
void		finish_program(void);
void		clear_last(void);
void		run_heredoc(char *file_name, t_program *node, int here_fds[2]);

//handle
void		sighandler(int signum);
void		sighandlerhc(int signum);
void		sighandlerquit(int signum);

//utils
int			count_strings(char **strings);
int			desired_len(char *str, char op);
void		free_lines(char	**lines);
long long	ft_atoi(const char *nptr);
int			ft_is_space(char c);
void		ft_putstr_fd(char *s, int fd);
int			ft_return_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strnstr(char *big, char *little, size_t n);
char		*get_filename(char *token);
char		*get_op(char *token);
int			is_alpha_num(char c);
char		*new_strjoin(char op, char const *s2);
void		print_program(t_program *node);
int			lstsize(t_program *curr);
int			flag_parse(char *flag, char type);
char		*ft_itoa(int n);
int			ft_isprint(int c);
char		*ft_strdup(const char *s);
int			has_non_numeric(const char *str);
int			ft_isalpha(char c);
char		*ft_strcat(char *s1, char *s2);
char		**sort_alpha(char **arr, int size);
char		*add_quotes(char *str);

//parse
int			check_syntax(char *g_line);
char		*expanded_dollar(char *input);
char		*expand_now(char *g_line, char a);
void		fill_pot(char *token, t_program *node);
void		fill_red(char *token, t_program *node);
void		parse_nodes(char **tokens, int node_id, char **nodes, char *treated);
char		*treat_and_replace(char *g_line);
char		*treat_quotes(char *token);
void		treat_infiles(char *file_name, t_program *node);
void		treat_outfiles(char *file_name, t_program *node);
void		treat_append(char *file_name, t_program *node);
char		*get_var(char *g_line, int s);
int			get_e(char *g_line, int s);
char		*insert_var(char *g_line, int s, char *var);
char		*expand_now(char *g_line, char a);

//builtins
int			check_builtin(t_program *curr);
int			do_builtin(t_program *curr);
int			is_builtin(char	*builtin, char *quoted_line);
int			my_cd(char **path);
int			my_echo(t_program *curr);
int			my_env(void);
void		my_exit(char **flags);
int			my_export(char **flags, t_program *curr);
int			my_pwd(char	**flags);
int			my_unset(char **flags);
size_t		ft_equal_len(const char *s);
int			if_exists(char	*str);
char		**printable_export(char **arr);
void		print_export(int fd);
void		add_var(char *str);

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
void		close_all(t_program *curr, int flag, int exitcode);
void		do_child(t_program *curr);
void		before_exec(t_program *curr);
void		after_exec(t_program *curr);


//apagar
void		print_double_arr(char **arr);

#endif