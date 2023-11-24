/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:05 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/23 18:27:41 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define BUFFER_SIZE 1


char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(const char *str);
int     ft_len(const char *buffer);
char	*ft_strcpy(char *dest, const char *src);
char *line(char *data, char c);
char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char *read_le(int fd, char *temp, char *data, int *byt);

#endif