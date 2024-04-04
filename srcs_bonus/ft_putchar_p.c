/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:30:57 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:19:18 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_putchar_p(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_pf(char c, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.left == 1)
		len += ft_putchar_p(c);
	len += ft_manage_width(flags.width, 1, flags.zero);
	if (flags.left == 0)
		len += ft_putchar_p(c);
	return (len);
}

int	ft_manage_width(int width, int size, int zero)
{
	int	len;

	len = 0;
	while (width - size > 0)
	{
		if (zero != 0)
			len += ft_putchar_p('0');
		else
			len += ft_putchar_p(' ');
		width--;
	}
	return (len);
}
