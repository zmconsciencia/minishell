/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:00:40 by bde-seic          #+#    #+#             */
/*   Updated: 2023/05/22 14:54:47 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../../../include/minishell.h"

// typedef struct s_program{
// 	int					fd[2];
// 	int					i;
// 	char				*path;
// 	char				**flags;
// 	struct s_program	*next;
// }	t_program;

void	pipex(t_program *program);
char	**get_path(char **envp);
char	*ft_strtrim(char *s1, char *set);
char	*trim_path(char *env_var);
char	*check_access(char **paths, char *arg);
char	*join_path(char *path, char *arg);
void	fill_list(t_program **list, int argc, char **argv, char **envp);
void	set_fd(t_program *curr, t_program **list, int argc, char **argv);
void	free_my_list(t_program *list);
void	ft_putstr_fd(char *s, int fd);

#endif