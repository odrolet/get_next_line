/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:03:20 by oldrolet          #+#    #+#             */
/*   Updated: 2023/03/22 13:42:30 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	*ft_calloc(size_t nitems, size_t size);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*ft_strchrg(char *str, int c);
char	*ft_strjoing(char *s1, char *s2);
size_t	ft_strleng(char *str);
char	*ft_get_line(char *stash);
void	*ft_free(char *str);

#endif
