/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:49:10 by rkochary          #+#    #+#             */
/*   Updated: 2022/04/25 16:54:42 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sline;
	char		*until_n;
	char		*tline;
	long		rsize;
	long		slinelen;

	rsize = 1;
	if (rsize == 0)
		return (NULL);
	sline = mywhile(fd, rsize, sline);
	if (!sline)
		return (NULL);
	slinelen = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	until_n = ft_substr(sline, 0, slinelen);
	tline = sline;
	sline = ft_substr(sline, slinelen, ft_strlen(sline));
	free(tline);
	return (until_n);
}

char	*mywhile(int fd, long rsize, char *sline)
{
	char		buffer[BUFFER_SIZE + 1];

	while (1)
	{	
		rsize = read(fd, buffer, BUFFER_SIZE);
		buffer[rsize] = '\0';
		if (rsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buffer);
		else
			sline = ft_strjoin(sline, buffer);
		if (ft_strchr(buffer, '\n') || rsize == 0)
			break ;
	}
	return (sline);
}
