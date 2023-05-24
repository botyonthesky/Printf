/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:09:45 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:18:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_short_p(va_list format)
{
	void	*ptr;

	ptr = va_arg(format, void *);
	if (ptr == NULL)
	{
		ft_putstr_p("(nil)");
		return (5);
	}
	else
	{
		ft_putstr_p("0x");
		return (ft_put_memory_adress(ptr) + 2);
	}
}

int	ft_short_u(va_list format)
{
	unsigned int	num;

	num = va_arg(format, unsigned int);
	if (num == 0)
	{
		ft_putchar_p('0');
		return (1);
	}
	else
		return (ft_putstr_p(ft_convert(num, "0123456789")));
}

int	ft_short_x(va_list format)
{
	unsigned int	numx;

	numx = va_arg(format, unsigned int);
	if (numx == 0)
	{
		ft_putchar_p('0');
		return (1);
	}
	else
		return (ft_putstr_p(ft_convert(numx, "0123456789abcdef")));
}

int	ft_short_gx(va_list format)
{
	unsigned int	numgx;

	numgx = va_arg(format, unsigned int);
	if (numgx == 0)
	{
		ft_putchar_p('0');
		return (1);
	}
	else
		return (ft_putstr_p(ft_convert(numgx, "0123456789ABCDEF")));
}

int	ft_check(char c, va_list format)
{
	if (c == 'c')
		return (ft_putchar_p(va_arg(format, int)));
	else if (c == 's')
		return (ft_putstr_p(va_arg(format, char *)));
	else if (c == 'p')
		return (ft_short_p(format));
	else if (c == 'd')
		return (ft_putnbr_p(va_arg(format, int)));
	else if (c == 'i')
		return (ft_putnbr_p(va_arg(format, int)));
	else if (c == 'u')
		return (ft_short_u(format));
	else if (c == 'x')
		return (ft_short_x(format));
	else if (c == 'X')
		return (ft_short_gx(format));
	else if (c == '%')
		return (ft_putchar_p('%'));
	return (0);
}

// char	*ft_convert(unsigned int x, char *set)
// {
// 	static char	tmp[50];
// 	char		*new;
// 	int			set_len;

// 	set_len = ft_strlen(set);
// 	new = &tmp[49];
// 	*new = '\0';
// 	while (x != 0)
// 	{
// 		new--;
// 		*new = set[x % set_len];
// 		x /= set_len;
// 	}
// 	return (new);
// }

// int	ft_printf(const char *format, ...)
// {
// 	va_list		args;
// 	int			i;
// 	int			len;

// 	va_start (args, format);
// 	i = 0;
// 	len = 0;
// 	while (format[i])
// 	{
// 		if (format[i] == '%')
// 		{
// 			len += ft_check(format[i + 1], args);
// 			i++;
// 		}
// 		else
// 			len += ft_putchar_p(format[i]);
// 	i++;
// 	}
// 	va_end(args);
// 	return (len);
// }

// int		main()
// {  
// 	printf("Test 1\t\t: Mod Check\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: %%\n");
//     printf("Output\t\t: ");
//     printf("%%\n\n");

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: %%\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%%\n\n");

//     //String Format Check
//     printf("Test 2\t\t: String Format Check\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: This is a test string.\n");
//     printf("Output\t\t: ");
//     printf("This is a test string.\n\n");

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: This is a test string.\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("This is a test string.\n\n");

//     //Specifier d check
//     printf("Test 3\t\t: d\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: 650\n");
//     printf("Output\t\t: ");
//     printf("%d\n\n", 650);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 650\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%d\n\n", 650);

//     printf("Function\t: Printf\n");
//     printf("Input\t\t: -650\n");
//     printf("Output\t\t: ");
//     printf("%d\n\n", -650);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: -650\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%d\n\n", -650);

//     //Specifier u check
//     printf("Test 17\t\t: u\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: 650\n");
//     printf("Output\t\t: ");
//     printf("%u\n\n", 650);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 650\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%u\n\n", 650);

//     // //Specifier u check
//     // printf("Test 18\t\t: u\n\n");
//     // printf("Function\t: Printf\n");
//     // printf("Input\t\t: 4000000000\n");
//     // printf("Output\t\t: ");
//     // printf("%u\n\n", 4000000000);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 4000000000\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%u\n\n", 4000000000);

//     //Specifier u check
//     printf("Test 18\t\t: u\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: -650\n");
//     printf("Output\t\t: ");
//     printf("%u\n\n", -650);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: -650\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%u\n\n", -650);

//      //Specifier s check
//     printf("Test 21\t\t: s\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: N/A\n");
//     printf("Output\t\t: ");
//     printf("%s\n\n", "");

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: N/A\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%s\n\n", "");

//     //Specifier s check

//     printf("Test 22\t\t: s\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: NULL\n");
//     printf("Output\t\t: ");
//     printf("%p\n\n", NULL);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: NULL\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%s\n\n", NULL);

//     //Specifier s check
//     printf("Test 24\t\t: s\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: Coconut\n");
//     printf("Output\t\t: ");
//     printf("%s\n\n", "Coconut");

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: Coconut\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%s\n\n", "Coconut");

//       //Specifier c check
//     printf("Test 30\t\t: c\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: a\n");
//     printf("Output\t\t: ");
//     printf("%c\n\n", 'a');

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: a\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%c\n\n", 'a');

//       //Specifier x check
//     printf("Test 50\t\t: x\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: 16\n");
//     printf("Output\t\t: ");
//     printf("%x\n\n", 16);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 16\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%x\n\n", 16);

//     //Specifier x check
//     printf("Test 51\t\t: x\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: 2048\n");
//     printf("Output\t\t: ");
//     printf("%x\n\n", 2048);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 2048\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%x\n\n", 2048);

//     //Specifier x check
//     printf("Test 52\t\t: x\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: 16777215\n");
//     printf("Output\t\t: ");
//     printf("%x\n\n", 16777215);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 16777215\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%x\n\n", 16777215);

//     //Specifier X check
//     printf("Test 53\t\t: X\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: 6777215\n");
//     printf("Output\t\t: ");
//     printf("%X\n\n", 6777215);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: 6777215\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%X\n\n", 6777215);

//     int     tmpInt;

//     tmpInt = 25;
//     //Specifier p check
//     printf("Test 58\t\t: p\n\n");
//     printf("Function\t: Printf\n");
//     printf("Input\t\t: &tmpInt\n");
//     printf("Output\t\t: ");
//     printf("%p\n\n", &tmpInt);

//     ft_printf("Function\t: ft_printf\n");
//     ft_printf("Input\t\t: &tmpInt\n");
//     ft_printf("Output\t\t: ");
//     ft_printf("%p\n\n", &tmpInt);

// 	return (0);
// }
