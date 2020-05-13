/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:56:47 by rvernius          #+#    #+#             */
/*   Updated: 2020/05/12 16:51:10 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define FD 15000

int				get_next_line(int fd, char **line);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s);
#endif
