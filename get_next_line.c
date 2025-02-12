/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 15:23:50 by rvernius          #+#    #+#             */
/*   Updated: 2020/05/13 21:08:09 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_make_new_line(char **fd_arr, char **line, char *p_new_line)
{
	char *temp;

	*p_new_line++ = '\0';
	*line = ft_strdup(*fd_arr);
	if (!*line)
		return (-1);
	if (*p_new_line == '\0')
	{
		free(*fd_arr);
		*fd_arr = NULL;
		return (1);
	}
	temp = ft_strdup(p_new_line);
	free(*fd_arr);
	*fd_arr = temp;
	return (1);
}

static int		ft_check_remainder(char **fd_arr, char **line, int bwr)
{
	char *p_new_line;

	if (bwr < 0)
		return (-1);
	if (*fd_arr && (p_new_line = ft_strchr(*fd_arr)))
		return (ft_make_new_line(fd_arr, line, p_new_line));
	if (*fd_arr)
	{
		*line = *fd_arr;
		*fd_arr = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*fd_arr[FD];
	char		buff[BUFFER_SIZE + 1];
	int			bwr;
	char		*p_new_line;

	if ((!line) || (fd < 0) || (read(fd, buff, 0) < 0))
		return (-1);
	while ((bwr = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bwr] = '\0';
		fd_arr[fd] = ft_strjoin(fd_arr[fd], buff);
		if (!fd_arr[fd])
			return (-1);
		if ((p_new_line = ft_strchr(fd_arr[fd])))
			return (ft_make_new_line(&fd_arr[fd], line, p_new_line));
	}
	return (ft_check_remainder(&fd_arr[fd], line, bwr));
}
