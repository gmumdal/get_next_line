/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:34 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/13 16:22:33 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	char		*toss;
	char		buf[BUFFER_SIZE + 1];
	static char	leave[BUFFER_SIZE + 1];

	if (BUFFER_SIZE == 0)
		return (0);
	toss = 0;
	toss = ft_strjoin(toss, leave, leave);
	while (*leave == 0 && ft_check(toss))
	{
		if (ft_read(fd, buf) <= 0)
		{
			if (*toss == 0)
			{
				free(toss);
				return (0);
			}
			return (toss);
		}
		toss = ft_strjoin(toss, buf, leave);
	}
	return (toss);
}
