/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:13:08 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/28 15:01:47 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len(char *buffer)
{
	int	le;

	le = 0;
	while (buffer[le] != '\n' && buffer[le])
	{
		le++;
	}
	if (buffer[le] == '\n')
		le++;
	return (le);
}

char	*ft_next(char *data)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	if (!data[i])
		return (free(data), NULL);
	next = ft_calloc((ft_strlen(data) - i + 1), sizeof(char));
	if (!next)
		return (free(data), NULL);
	while (data[i])
		next[j++] = data[i++];
	next[j++] = '\0';
	free(data);
	return (next);
}

char	*ft_line(char *data)
{
	char	*line;
	int		i;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (data[i] && data[i] != '\n')
	{
		line[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *data)
{
	char	*temp;
	int		byte;

	if (!data)
		data = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte > 0 && !ft_strchr(temp, '\n'))
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(data);
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		data = ft_strjoin(data, temp);
	}
	free(temp);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
		return (NULL);
	data[fd] = read_file(fd, data[fd]);
	if (data[fd] == NULL)
		return (NULL);
	if (ft_len(data[fd]) == 0)
	{
		free(data[fd]);
		data[fd] = NULL;
		return (NULL);
	}
	line = ft_line(data[fd]);
	data[fd] = ft_next(data[fd]);
	return (line);
}
