/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:25:08 by marco             #+#    #+#             */
/*   Updated: 2024/10/29 09:36:38 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buffer(char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	if (!str)
	{
		free (buff);
		return (NULL);
	}
	i++;
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	free(buff);
	return (str);
}

static char	*ft_mountline(char *buff)
{
	int		i;
	char	*aux;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	aux = ft_calloc(sizeof(char), (i + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

static char	*ft_read(int fd, char *buff)
{
	int		read_bytes;
	char	*aux;

	aux = ft_calloc((BUFFER_SIZE + 2), sizeof(char));
	if (!aux)
		return (NULL);
	read_bytes = 1;
	while (!(ft_strchr(buff, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (buff != NULL)
				free(buff);
			free(aux);
			return (NULL);
		}
		aux[read_bytes] = '\0';
		buff = ft_strjoin(buff, aux);
	}
	free(aux);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buff)
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	buff = ft_read(fd, buff);
	if (!buff)
	{
		free (buff);
		return (NULL);
	}
	line = ft_mountline(buff);
	buff = ft_buffer(buff);
	return (line);
}

//int main()
//{
//    int fd;
//	char *line;
//
//    fd = open("empty.txt", O_RDONLY);
//    if (fd == -1) 
//	{
//        printf("Error al abrir el archivo");
//        return (1);
//    }
//    for (int i = 0; i < 2; i++)
//    {
//		line = get_next_line(fd);
//        printf("[%i] %s", i + 1, line);
//		free (line);
//    }
//    // Realiza operaciones con el archivo (lectura/escritura)
//
//    close(fd); // Cerrar el archivo
//    return (0);
//}