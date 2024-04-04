/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:07:58 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:09:17 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_check_plus(char c, va_list format, t_listf flags)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_pf(va_arg(format, int), flags);
	else if (c == 's')
		len += ft_putstr_pf(va_arg(format, const char *), flags);
	else if (c == 'p')
		len += ft_putptr_pf((unsigned long int)va_arg(format, void *), flags);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_pf(va_arg(format, int), flags);
	else if (c == 'u')
		len += ft_putunsigned(va_arg(format, unsigned int), flags);
	else if (c == 'x')
		len += ft_puthex(va_arg(format, unsigned int), 0, flags);
	else if (c == 'X')
		len += ft_puthex(va_arg(format, unsigned int), 1, flags);
	else if (c == '%')
		len += ft_putchar_pf('%', flags);
	return (len);
}

char	*ft_xtoa(unsigned long int n, char *str, size_t len)
{
	int	mod;

	mod = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len != (size_t)-1)
	{
		mod = n % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else if (mod >= 10)
			str[len] = (mod - 10) + 'a';
		n = n / 16;
		len--;
	}
	return (str);
}

char	*ft_utoa(unsigned int n, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[0] = (n % 10) + '0';
	return (str);
}
