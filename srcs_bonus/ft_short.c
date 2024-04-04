/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:38 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:02:43 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "include/ft_printf_bonus.h"

char	*ft_short_itoan(long n)
{
	size_t	len;
	char	*new;

	len = 0;
	new = NULL;
	len = ft_itoanlen(n);
	new = ft_itoan(n, new, len);
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*ft_short_xtoa(unsigned int n, int ucase)
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_xtoalen(n);
	str = NULL;
	str = ft_xtoa(n, str, len);
	if (str == NULL)
		return (NULL);
	if (ucase == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}

char	*ft_short_utoa(unsigned int n)
{
	size_t	len;
	char	*str;

	len = ft_utoalen(n);
	str = 0;
	str = ft_utoa(n, str, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
