/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:32:19 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/13 10:54:40 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int	ft_putstr_p(char *str)
{
	if (str == NULL)
		return (ft_putstr_p("(null)"));
	if (str == 0)
		return (ft_putstr_p(NULL));
	return (write(1, str, ft_strlen(str)));
}
