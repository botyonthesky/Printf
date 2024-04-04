/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:02:59 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:06:22 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_puthex(unsigned int n, int ucase, t_listf flags)
{
	char	*new;
	int		len;

	len = 0;
	if (n == 0 && flags.precision == 0)
	{
		len += ft_manage_width(flags.width, 0, 0);
		return (len);
	}
	new = ft_short_xtoa(n, ucase);
	if (new == NULL)
		return (0);
	len += ft_manage_hex(new, n, ucase, flags);
	free(new);
	return (len);
}

int	ft_manage_hex(char *new, int n, int ucase, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.zero == 1 && flags.sharp == 1 && n != 0)
		len += ft_manage_sharp(ucase);
	if (flags.left == 1)
		len += ft_manage_hex_precis(new, n, ucase, flags);
	if (flags.precision >= 0 && flags.precision < ft_strlen_i(new))
		flags.precision = ft_strlen(new);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		len += ft_manage_width(flags.width, 0, 0);
	}
	else
		len += ft_manage_width(flags.width,
				ft_strlen(new) + (flags.sharp * 2), flags.zero);
	if (flags.left == 0)
		len += ft_manage_hex_precis(new, n, ucase, flags);
	return (len);
}

int	ft_manage_hex_precis(char *new, int n, int ucase, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.zero == 0 && flags.sharp == 1 && n != 0)
		len += ft_manage_sharp(ucase);
	if (flags.precision >= 0)
		len += ft_manage_width(flags.precision - 1,
				ft_strlen(new) - 1, 1);
	len += ft_putstr_p(new);
	return (len);
}
