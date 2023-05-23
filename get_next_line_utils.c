/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:06:48 by oldrolet          #+#    #+#             */
/*   Updated: 2023/03/17 17:35:38 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*ft_strchrg(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	else
		return (NULL);
}

size_t	ft_strleng(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (nitems * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoing(char *s1, char *s2)
{
	char	*nouv;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL)
	{
		s1 = ft_calloc(sizeof(char), 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = 0;
	}
	nouv = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (nouv == NULL)
		return (NULL);
	while (s1[++i])
		nouv[i] = s1[i];
	while (s2[++j] != '\0')
		nouv[i + j] = s2[j];
	nouv[i + j] = '\0';
	return (s1 = ft_free(s1), nouv);
}
