/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:26:27 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/05 16:23:51 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(int n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static void	ft_short(size_t i, size_t j, long n, char *new)
{
	while (j > i)
	{
		new[j - 1] = '0' + n % 10;
		n = n / 10;
		j--;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*new;
	long	n2;

	n2 = n;
	j = ft_length(n);
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		return (NULL);
	if (n2 < 0)
	{
		new[0] = '-';
		n2 = -n2;
		i = 1;
	}
	else
		i = 0;
	ft_short(i, j, n2, new);
	new[j] = '\0';
	return (new);
}

/*#include <stdio.h>

int	main()
{
	printf("\n---- itoa ----\n");
        printf("48 to string : %s\n", ft_itoa(48));
        printf("0 to string : %s\n", ft_itoa(0));
        printf("-6115048 to string : %s\n", ft_itoa(-6115048));
        printf("2147483647 to string : %s\n", ft_itoa(2147483647));
        printf("-2147483648 to string : %s\n", ft_itoa(-2147483648));

	return (0);
}*/
