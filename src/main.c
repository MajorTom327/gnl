/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:08:51 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/15 19:40:55 by vthomas          ###   ########.fr       */
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
	fd = open("./lorem", O_RDWR);
	tmp = 0;
	ft_putendl("START WORKING");
//	get_next_line(fd, &str);
//	ft_putstr(str);
	while (get_next_line(fd, &str))
	{
		ft_putnbr(tmp);
		ft_putstr("\t-\t");
 		ft_putstr(str);
		tmp++;
	}
	//ft_putendl(str);
	ft_putendl("STOP WORKING");
	close(fd);
	return (0);
}
