/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:35:00 by dgallard          #+#    #+#             */
/*   Updated: 2021/01/07 20:42:39 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_free(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	int		len_joined;
	char	*strjoined;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len_joined = ft_strlen(str1) + ft_strlen(str2);
	if (!(strjoined = (char *)malloc(len_joined + 1)))
		return (NULL);
	len_str1 = 0;
	len_str2 = 0;
	len_joined = 0;
	while (str1[len_str1] != '\0')
		strjoined[len_joined++] = str1[len_str1++];
	while (str2[len_str2] != '\0')
		strjoined[len_joined++] = str2[len_str2++];
	strjoined[len_joined] = '\0';
	free(str1);
	return (strjoined);
}

char	*ft_malloc(char **str, int size)
{
	if (!(*str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	*str[0] = '\0';
	return (*str);
}

char	*ft_tail_handle(char **tail)
{
	char	*tmp;
	int		iter_n;

	if (*tail)
	{
		if (ft_nmbr_sn(*tail) > 0)
		{
			iter_n = ft_nmbr_symb_bf_sn(*tail);
			ft_malloc(&tmp, 1);
			tmp = ft_strjoin_free(tmp, *tail);
			*tail[0] = '\0';
			*tail = ft_strjoin_free(*tail, &tmp[iter_n + 1]);
			tmp[iter_n] = '\0';
			return (tmp);
		}
		ft_malloc(&tmp, ft_strlen(*tail));
		tmp = ft_strjoin_free(tmp, *tail);
		free(*tail);
		*tail = NULL;
		return (tmp);
	}
	else
		ft_malloc(&tmp, 1);
	return (tmp);
}

char	*ft_buf_read(int fd, int *bytes_read, char **tail, char **tmp)
{
	int		iter_n;
	size_t	nmbr_sn;
	char	buf[BUFFER_SIZE + 1];
	
	nmbr_sn = 0;
	while (nmbr_sn == 0 && *bytes_read != 0 && !*tail)
	{
		*bytes_read = read(fd, buf, BUFFER_SIZE);
		if (*bytes_read < 0)
			return (NULL);
		buf[*bytes_read] = '\0';
		iter_n = ft_nmbr_symb_bf_sn(buf);
		if (ft_nmbr_sn(buf) >= 1)
		{
			if (!(ft_malloc(tail, (*bytes_read - iter_n))))
				return (NULL);
			*tail = ft_strjoin_free(*tail, &buf[iter_n + 1]);
			buf[iter_n] = '\0';
		}
		*tmp = ft_strjoin_free(*tmp, buf);
	}
	return (*tmp);
}
