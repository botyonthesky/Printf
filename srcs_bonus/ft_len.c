/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:20:16 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:20:52 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

size_t	ft_utoalen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_xtoalen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	ft_itoanlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_strlen_i(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
