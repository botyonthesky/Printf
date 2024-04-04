/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:14:31 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:15:17 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_putptr_pf(unsigned long int n, t_listf flags)
{
	int	len;

	len = 0;
	if (n == 0)
		flags.width -= ft_strlen(("(nil)")) - 1;
	else
		flags.width -= 2;
	if (flags.left == 1)
		len += ft_manage_adress(n);
	len += ft_manage_width(flags.width, ft_ptrlen(n), 0);
	if (flags.left == 0)
		len += ft_manage_adress(n);
	return (len);
}

int	ft_manage_adress(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_putstr_p("(nil)");
		return (len);
	}
	len += ft_putstr_p("0x");
	ft_put_adress(n);
	len += ft_ptrlen(n);
	return (len);
}

void	ft_put_adress(unsigned long int n)
{
	if (n >= 16)
	{
		ft_put_adress(n / 16);
		ft_put_adress(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_p(n + '0');
		else if (n >= 10)
			ft_putchar_p((n - 10) + 'a');
	}
}

int	ft_ptrlen(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 16;
	}
	return (len);
}
