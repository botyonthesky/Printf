/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:06:35 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:07:44 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_putunsigned(unsigned n, t_listf flags)
{
	char	*new;
	int		len;

	len = 0;
	if (n == 0 && flags.precision == 0)
	{
		len += ft_manage_width(flags.width, 0, 0);
		return (len);
	}
	new = ft_short_utoa(n);
	if (new == NULL)
		return (0);
	len += ft_manage_unsigned(new, flags);
	free(new);
	return (len);
}

int	ft_manage_unsigned(char *new, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.left == 1)
		len += ft_manage_unsigned_precis(new, flags);
	if (flags.precision >= 0 && flags.precision < ft_strlen_i(new))
		flags.precision = ft_strlen(new);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		len += ft_manage_width(flags.width, 0, 0);
	}
	else
		len += ft_manage_width(flags.width, ft_strlen(new), flags.zero);
	if (flags.left == 0)
		len += ft_manage_unsigned_precis(new, flags);
	return (len);
}

int	ft_manage_unsigned_precis(char *new, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.precision >= 0)
		len += ft_manage_width(flags.precision - 1, ft_strlen(new) - 1, 1);
	len += ft_putstr_p(new);
	return (len);
}
