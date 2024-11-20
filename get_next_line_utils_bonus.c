/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:25:38 by marco             #+#    #+#             */
/*   Updated: 2024/10/29 09:41:29 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!s3)
		return (NULL);
	while (s1[j])
	{
		s3[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = '\0';
	free (s1);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmeb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmeb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	int				i;

	i = 0;
	a = s;
	while (n > 0)
	{
		a[i] = '\0';
		i++;
		n--;
	}
	s = a;
}
