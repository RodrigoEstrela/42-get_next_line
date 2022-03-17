/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:29:41 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/17 17:00:42 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_nl(int fd, char *buffer, char *str, char *save)
{
	int		i;

	i = 1;
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		if (!str)
		{
			str = (char *)malloc(1);
			str[0] = '\0';
		}
		buffer[i] = '\0';
		save = str;
		str = ft_strjoin(save, buffer);
		free (save);
	}
	return (str);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*save;

	if (read(fd, 0, 0) == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	save = NULL;
	str = get_nl(fd, buffer, str, save);
	if (ft_strlen(str) == 0)
	{
		free(str);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	save = ft_strnldup(str);
	str = ft_exstrchr(str);
	return (save);
}

int main()
{
	int fd = open("file1.txt", O_RDWR);
	/*printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
	printf("%s\n", (char *)0);
	printf("%s\n", "");
	get_next_line(fd);i*/
	char *line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
}
