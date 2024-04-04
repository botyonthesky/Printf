/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:21:49 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:12:54 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	char		*str;

	len = 0;
	if (format == NULL || *format == '\0')
		return (0);
	str = ft_strdup(format);
	va_start (args, format);
	len = ft_printf_flag(str, args);
	va_end(args);
	free(str);
	return (len);
}

int	ft_printf_flag(char *str, va_list args)
{
	int		i;
	int		f;
	int		len;
	t_listf	flags;

	i = 0;
	len = 0;
	while (str[i])
	{
		flags = ft_init_flaglist();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			f = ft_manage_flags(str, i, &flags);
			if (flags.spec > 0)
				i = f;
			if (str[i] != '\0' && flags.spec > 0 && ft_is_speci(str[i]))
				len += ft_check_plus(str[i], args, flags);
			else if (str[i] != '\0')
				len += ft_putchar_p(str[i]);
		}
		else
			len += ft_putchar_p(str[i]);
		i++;
	}
	return (len);
}

t_listf	ft_init_flaglist(void)
{
	t_listf	flags;

	flags.spec = 0;
	flags.width = 0;
	flags.left = 0;
	flags.zero = 0;
	flags.precision = -1;
	flags.sharp = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}
