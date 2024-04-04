/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:32:10 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/13 14:29:04 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

/*---------------Base---------------------*/

int		ft_printf(const char *s, ...);
char	*ft_convert(unsigned int x, char *set);

/*---------------Shortcut fonctions---------------------*/

int		ft_short_p(va_list fornat);
int		ft_short_u(va_list format);
int		ft_short_x(va_list format);
int		ft_short_gx(va_list format);

/*---------------Specifiers fonctions---------------------*/

int		ft_putchar_p(char c);
int		ft_putstr_p(char *str);
int		ft_putnbr_p(int n);
int		ft_put_memory_adress(void *ptr);

/*---------------Check---------------------*/

int		ft_check(char c, va_list format);

#endif
