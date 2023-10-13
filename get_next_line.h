/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:36:51 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/13 15:01:15 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int			fd;
	char		leave[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(char *receive, char *buf, char *leave);
char	*get_next_line(int fd);
int		ft_len(char *str);
char	*ft_strncpy(char *dst, char *src, int n);
int		ft_read(int fd, char *buf);
int		ft_check(char *toss);

#endif
