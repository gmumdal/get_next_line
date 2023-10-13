/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:34 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/13 15:01:17 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*a;
	int		fd = open(av[1], O_RDONLY);
	
	ac++;
	a = av[1];
	while (a != 0)
	{
		a = get_next_line(fd);
		printf("a in main: [%s]\n", a);
	}
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	count;

	if (dst == 0 && src == 0)
		return (dst);
	count = 0;
	while (count < n && src[count] != 0)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = 0;
	return (dst);
}

int	ft_len(char *str)
{
	int	size;

	if (str == 0)
		return (0);
	size = 0;
	while (str[size] != 0 && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}

char	*ft_strjoin(char *receive, char *buf, char *leave)
{
	char	*toss;
	int		i;
	int		j;
	int		len;

	toss = (char *)malloc(ft_len(receive) + ft_len(buf) + 1);
	i = -1;
	len = ft_len(receive);
	while (++i < len)
		toss[i] = receive[i];
	j = -1;
	len = ft_len(buf);
	while (++j < len)
		toss[i + j] = buf[j];
	toss[i + j] = 0;
	if (buf[j] != 0)
		leave = ft_strncpy(leave, &buf[j], BUFFER_SIZE - j);
	else
		*leave = 0;
	free(receive);
	return (toss);
}

int	ft_read(int fd, char *buf)
{
	int i;

	i = -1;
	while (++i < BUFFER_SIZE + 1)
		buf[i] = 0;
	return (read(fd, buf, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	char		*toss;
	char		buf[BUFFER_SIZE + 1];
	static char	leave[BUFFER_SIZE + 1] = {0, };

	if (BUFFER_SIZE == 0)
		return (0);
	toss = 0;
	toss = ft_strjoin(toss, leave, leave);
	while (*leave == 0 && ft_check(toss))
	{
		if (ft_read(fd, buf) == 0)
		{
			if (*toss == 0)
				return (0);
			return (toss);
		}
		toss = ft_strjoin(toss, buf, leave);
	}
	return (toss);
}

int	ft_check(char *toss)
{
	while (*toss)
	{
		if (*toss == '\n')
			return (0);
		toss++;
	}
	return (1);
}
