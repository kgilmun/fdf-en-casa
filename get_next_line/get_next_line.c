/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:54:39 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/02/28 19:08:11 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*store_line_peace(char *str)
{
	char	*line_peace;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line_peace = ft_strdup(str + i);
	free(str);
	return (line_peace);
}

char	*line_return(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

void	gnl_loop(char **buffer, char **temp, char **store)
{
	if (!*store)
		*store = ft_strdup("");
	*temp = ft_strjoin(*store, *buffer);
	free(*store);
	*store = ft_strdup(*temp);
	free(*temp);
	free(*buffer);
}

void	modify_line(char **line, char **store)
{
	*line = line_return(*store);
	*store = store_line_peace(*store);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			rd;
	static char	*store = NULL;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	while (rd != 0)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (!buffer)
			return (NULL);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (free(buffer), NULL);
		buffer[rd] = '\0';
		gnl_loop(&buffer, &temp, &store);
		if (ft_strchr(store, '\n'))
			break ;
	}
	if (!store || !*store)
		return (free(store), store = NULL, NULL);
	return (modify_line(&line, &store), line);
}
