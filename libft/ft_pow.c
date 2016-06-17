/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 21:32:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/12 17:33:23 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int nb, int pow)
{
	if (pow > 1)
		return (nb * ft_pow(nb, pow - 1));
	if (pow <= 0)
		return (1);
	return (nb);
}
