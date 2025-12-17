/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 03:01:25 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/08/28 03:01:26 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_puthexl(unsigned int n)
{
	const char	*base;
	char		c;
	int			i;

	i = 0;
	c = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		i += ft_puthexl(n / 16);
	c = base[n % 16];
	i += write(1, &c, 1);
	return (i);
}
