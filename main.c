/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/07/14 03:08:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		ret;
	int		turn;

	if (ac > 1)
		fd = open(av[1], O_WRONLY);
	else
		fd = open("./f_test", O_WRONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
	write(fd, "1234", 4);
	close(fd);
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("./f_test", O_RDONLY);
	ft_putnbr_endl(fd);
	turn = 0;
	ret = get_next_line(fd, &str);
	if (ret)
		ft_putendl("First Return\t\033[32m[OK]\033[0m");
	else
		ft_putendl("First Return\t\033[31m[BAD]\033[0m");
	if (ft_strcmp(str, "1234") == 0)
		ft_putendl("String is\t\033[32m[OK]\033[0m");
	else
		ft_putendl("String is\t\033[31m[BAD]\033[0m");
	if (str == NULL)
		ft_putendl("String is\t\033[31m[EMPTY]\033[0m");
	else
	{
		ft_putstr("String is\t\033[32m[CONTAINING SOMETHING]\033[0m\t\t[");
		ft_putstr(str);
		ft_putendl("]");
	}

	ret = get_next_line(fd, &str);
	if (!ret)
		ft_putendl("Last Return\t\033[32m[OK]\033[0m");
	else
		ft_putendl("Last Return\t\033[31m[BAD]\033[0m");
	if (str == NULL)
		ft_putendl("String is\t\033[32m[EMPTY]\033[0m");
	else
	{
		ft_putstr("String is\t\033[31m[CONTAINING SOMETHING]\033[0m\t\t[");
		ft_putstr(str);
		ft_putendl("]");
	}
	close(fd);
	return (EXIT_SUCCESS);
}
