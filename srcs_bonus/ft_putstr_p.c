/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:32:19 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:19:58 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_putstr_p(char *str)
{
	if (str == NULL)
		return (ft_putstr_p("(null)"));
	if (str == 0)
		return (ft_putstr_p(NULL));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putstr_pf(const char *str, t_listf flags)
{
	int	len;

	len = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
	{
		len += ft_manage_width(flags.width, 0, 0);
		return (len);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && flags.precision > ft_strlen_i(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		len += ft_putstr_left(str, flags);
	if (flags.precision >= 0)
		len += ft_manage_width(flags.width, flags.precision, 0);
	else
		len += ft_manage_width(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		len += ft_putstr_left(str, flags);
	return (len);
}

int	ft_putstr_left(const char *str, t_listf flags)
{
	int	len;

	len = 0;
	if (flags.precision >= 0)
	{
		len += ft_manage_width(flags.precision, ft_strlen(str), 0);
		len += ft_putstr_preci(str, flags.precision);
	}
	else
		len += ft_putstr_preci(str, ft_strlen(str));
	return (len);
}

int	ft_putstr_preci(const char *str, int precis)
{
	int	len;

	len = 0;
	while (str[len] && len < precis)
		write(1, &str[len++], 1);
	return (len);
}
