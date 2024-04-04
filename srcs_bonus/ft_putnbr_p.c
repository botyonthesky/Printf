/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:35:41 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:22:42 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_putnbr_pf(int n, t_listf flags)
{
	int		len;
	long	nbr;
	char	*new;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		if (flags.zero == 0)
			flags.width--;
	}
	if (flags.precision == 0 && n == 0)
	{
		len += ft_manage_width(flags.width, 0, 0);
		return (len);
	}
	new = ft_short_itoan(nbr);
	if (new == NULL)
		return (0);
	len += ft_manage_nbr(new, n, flags);
	free(new);
	return (len);
}

char	*ft_itoan(long n, char *new, size_t len)
{
	new = ft_calloc(len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	if (n < 0)
	{
		new[0] = '-';
		n *= -1;
	}
	len--;
	while (len)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (new[0] != '-')
		new[0] = (n % 10) + '0';
	return (new);
}

int	ft_manage_nbr(char *new, int n, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.zero == 1)
		len += ft_manage_pms_nbr(n, &flags);
	if (flags.left == 1)
		len += ft_manage_pms_precis(new, n, flags);
	if (flags.precision >= 0 && flags.precision < ft_strlen_i(new))
		flags.precision = ft_strlen(new);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		if (n < 0 && flags.left == 0)
			flags.width -= 1;
		len += ft_manage_width(flags.width, 0, 0);
	}
	else
		len += ft_manage_width(flags.width - flags.plus - flags.space,
				ft_strlen(new), flags.zero);
	if (flags.left == 0)
		len += ft_manage_pms_precis(new, n, flags);
	return (len);
}

int	ft_manage_pms_nbr(int n, t_listf *flags)
{
	int	len;

	len = 0;
	if (n < 0 && flags->precision == -1)
	{
		len += ft_putchar_p('-');
		flags->width--;
	}
	else if (flags->plus == 1)
		len += ft_putchar_p('+');
	else if (flags->space == 1)
	{
		len += ft_putchar_p(' ');
		flags->width--;
	}
	return (len);
}

int	ft_manage_pms_precis(char *new, int n, t_listf flags)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			len += ft_putchar_p('-');
	}
	else if (flags.plus == 1 && flags.zero == 0)
		len += ft_putchar_p('+');
	else if (flags.space == 1 && flags.zero == 0)
		len += ft_putchar_p(' ');
	if (flags.precision >= 0)
		len += ft_manage_width(flags.precision - 1, ft_strlen(new) - 1, 1);
	len += ft_putstr_p(new);
	return (len);
}
