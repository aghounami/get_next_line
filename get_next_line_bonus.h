/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:13:19 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/28 15:04:47 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <libc.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_next(char *data);
char	*ft_line(char *data);
char	*read_file(int fd, char *data);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(int count, int size);
void	ft_bzero(void *s, int n);
int		ft_strlen(const char *str);
int		ft_len(char *buffer);

#endif