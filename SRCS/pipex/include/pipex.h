/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:00:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/03/08 13:09:15 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_program{
	int					fd[2];
	int					i;
	char				*path;
	char				**flags;
	struct s_program	*next;
}	t_program;

char	**get_path(char **envp);
char	*ft_strnstr(char *big, char *little, size_t n);
char	*ft_strtrim(char *s1, char *set);
int		ft_strlen(char *s);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*trim_path(char *env_var);
char	**ft_split(char const *s, char c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*check_access(char **paths, char *arg);
char	*ft_strjoin(char *s1, char *s2);
char	*join_path(char *path, char *arg);
void	fill_list(t_program **list, int argc, char **argv, char **envp);
void	set_fd(t_program *curr, t_program **list, int argc, char **argv);
void	free_my_list(t_program *list);
void	ft_putstr_fd(char *s, int fd);

#endif
