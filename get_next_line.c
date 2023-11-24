/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:27 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/23 18:41:23 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_le(int fd, char *temp, char *data, int *byt)
{
    *byt = read(fd, temp, BUFFER_SIZE);
    if (*byt == -1)
    {
        return NULL;
    }
    else if (*byt > 0)
    {
        temp[*byt] = '\0';
        data = ft_strjoin(data, temp);
        return data;
    }
    return NULL;
}

char *get_next_line(int fd)
{
    char *temp;
    int byt;
    static char *data;

    if (!data)
        data = ft_strdup("");
    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
    {
        free(data);
        return NULL;
    }

    while ((byt = (int)read_le(fd, temp, data, &byt)) > 0 && !ft_strchr(data, '\n'))
    {
        free(temp);
        temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!temp)
        {
            free(data);
            return NULL;
        }
    }

    char *res = line(data, '\n');
    if (res)
    {
        *res = '\0';
        char *line = ft_strdup(data);
        data = ft_strdup(res + 1);
        free(res);
        free(temp);
        return line;
    }
    else if (byt == 0 && *data)
    {
        char *line = ft_strdup(data);
        free(data);
        data = NULL;
        free(temp);
        return line;
    }

    free(temp);

    return NULL;
}
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0666);
    printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    close(fd);
    // printf("%s", get_next_line(fd));
}
