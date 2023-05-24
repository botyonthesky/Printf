/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:10:21 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/05 14:03:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*d;
	const char		*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (d > s)
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	printf("\n---- memmove ----\n");
        char str_test7[] = "memmove can be very useful.";
        char str_real7[] = "memmove can be very useful.";
        ft_memmove(str_test7 + 20, str_test7 + 15, 11);
        memmove(str_real7 + 20, str_real7 + 15, 11);
        printf("Real : %s\n", str_real7);
        printf("Test : %s\n", str_test7);

	return (0);
}*/
