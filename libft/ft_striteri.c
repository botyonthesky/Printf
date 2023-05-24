/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:07:56 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/10 09:04:44 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	ft_upper(unsigned int i, char *c)
{
	if(*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}

int	main()
{
	char	x[] = "hello";
	
	ft_striteri(x, ft_upper);

	printf("%s\n", x);

	return (0);
}*/
