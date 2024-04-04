/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:55:10 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/13 10:56:10 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			len;

	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_check(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar_p(format[i]);
	i++;
	}
	va_end(args);
	return (len);
}
