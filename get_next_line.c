/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:04:12 by ymoustai          #+#    #+#             */
/*   Updated: 2018/12/21 21:49:23 by ymoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*s[4864];
	int			i;

	i = 0;
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buff);
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	*line = ft_strsub(s[fd], 0, i);
	if (!ft_strlen(s[fd]) && !ret && !i)
		return (0);
	s[fd] = ft_strdup(s[fd] + i + 1);
	return (1);
}
