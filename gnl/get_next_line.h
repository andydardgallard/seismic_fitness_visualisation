/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:30:26 by dgallard          #+#    #+#             */
/*   Updated: 2021/01/07 20:43:06 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
size_t		ft_nmbr_symb_bf_sn(char *str);
size_t		ft_nmbr_sn(char *str);
int			ft_strlen(char *str);
char		*ft_strjoin_free(char *str1, char *str2);
char		*ft_malloc(char **str, int size);
char		*ft_tail_handle(char **tail);
char		*ft_buf_read(int fd, int *bytes_read, char **tail, char **tmp);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 35
# endif

#endif
