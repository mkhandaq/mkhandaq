/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:26:33 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/12/06 18:23:29 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_arglen(char **s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
