/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:08:51 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/26 08:17:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*str;
	int		fd;
	int		tmp;

	str = ft_strnew(90);
	fd = open("./bigfile", O_RDWR);
	tmp = 0;
	while (get_next_line(fd, &str))
	{
//		ft_putnbr(tmp);
//		ft_putstr("\t-\t");
		ft_putstr(str);
//		ft_putstr("\t-\t");
//		ft_putendl(&str[ft_strlen(str) + 1]);
		tmp++;
	}
	ft_putendl("");
	close(fd);
	return (0);
}
