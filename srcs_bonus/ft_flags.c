/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:34:04 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:18:39 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

int	ft_manage_flags(const char *str, int i, t_listf *flags)
{
	while (str[i++] && ft_is_flags(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_manage_precision(str, i, flags);
		if (str[i] == '#')
			flags->sharp = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (ft_isdigit(str[i]))
			*flags = ft_manage_digit(str[i], *flags);
		if (ft_is_speci(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
	}
	return (i);
}

t_listf	ft_flag_left(t_listf flags)
{
	flags.left = 1;
	flags.zero = 0;
	return (flags);
}

int	ft_is_flags(int c)
{
	return (ft_is_speci(c) || ft_isdigit(c) || ft_is_flag(c));
}

int	ft_is_speci(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == '%')
		return (1);
	else
		return (0);
}

int	ft_is_flag(int c)
{
	if (c == '-' || c == '0' || c == '.'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	else
		return (0);
}
