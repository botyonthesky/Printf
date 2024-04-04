/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:12:25 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:09:58 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

t_listf	ft_manage_digit(char c, t_listf flags)
{
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int	ft_manage_precision(const char *str, int i, t_listf *flags)
{
	int	cur;

	cur = i + 1;
	flags->precision = 0;
	while (ft_isdigit(str[cur]))
	{
		flags->precision = (flags->precision * 10) + (str[cur] - '0');
		cur++;
	}
	return (cur);
}

int	ft_manage_sharp(int ucase)
{
	if (ucase == 1)
		ft_putstr_p("0X");
	else
		ft_putstr_p("0x");
	return (2);
}
