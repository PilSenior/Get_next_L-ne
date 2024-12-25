/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:51:12 by htekdemi          #+#    #+#             */
/*   Updated: 2024/12/24 00:51:12 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	p;

	p = 0;
	while (str[p] != '\0')
		p++;
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (free(s1),NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if(!s1)
			return(NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *r2, int c)
{
	int	i;

	if (!r2)
		return (0);
	i = 0;
	while (r2[i])
	{
		if (r2[i] == c)
			return ((char *)r2 + i);
		i++;
	}
	return (NULL);
}
