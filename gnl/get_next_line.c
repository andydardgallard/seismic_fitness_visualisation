/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:32:58 by dgallard          #+#    #+#             */
/*   Updated: 2021/01/08 00:35:49 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_nmbr_symb_bf_sn(char *str)
{
	size_t		nmbr;

	nmbr = 0;
	while (str[nmbr] != '\0')
	{
		if (str[nmbr] == '\n')
			break ;
		nmbr++;
	}
	return (nmbr);
}

size_t		ft_nmbr_sn(char *str)
{
	size_t		nmbr;
	size_t		iter;

	nmbr = 0;
	iter = 0;
	while (str[iter] != '\0')
	{
		if (str[iter] == '\n')
			nmbr++;
		iter++;
	}
	return (nmbr);
}

int			get_next_line(int fd, char **line)
{
	int				bytes_read;
	char			*tmp;
	static char		*tail;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	bytes_read = 1;
	tmp = ft_tail_handle(&tail);
	tmp = ft_buf_read(fd, &bytes_read, &tail, &tmp);
	*line = tmp;
	if (tmp == NULL)
		return (-1);
	if (bytes_read)
		return (1);
	return (0);
}
