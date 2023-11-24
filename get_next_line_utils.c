/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:02:51 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/23 18:42:14 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_len(const char *buffer)
{
	int le = 0;
	while (buffer[le] != '\n' && buffer[le])
	{
		le++;
	}
	if (buffer[le] == '\n')
		le++;
	return le;
}

char *ft_strdup(const char *str)
{
	int len = ft_len(str);
	char *dup = malloc(len + 1);
	if (dup == NULL)
		return NULL;
	ft_strcpy(dup, str);
	return dup;
}

char *ft_strjoin(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return NULL;

	int len_s1 = ft_len(s1);
	int len_s2 = ft_len(s2);

	char *join = malloc(len_s1 + len_s2 + 1);
	if (join == NULL)
		return NULL;

	ft_strcpy(join, s1);
	ft_strcpy(join + len_s1, s2);
	// free(s1);
	// free(s2);
	return join;
}

char *line(char *data, char c)
{
	int i = 0;
	while (data[i] != c && data[i] != '\0')
	{
		i++;
	}

	char *res = malloc(i + 1);
	if (res == NULL)
	{

		return NULL;
	}

	for (int j = 0; j < i; j++)
	{
		res[j] = data[j];
	}

	res[i] = '\0';

	return res;
}
char *ft_strcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char *ft_strchr(const char *s, int c)
{
	char *str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
		{
			return str;
		}
		str++;
	}
	if ((char)c == '\0')
	{
		return str;
	}
	return NULL;
}
