/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:22:23 by tmaillar          #+#    #+#             */
/*   Updated: 2023/12/22 09:00:14 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_listf
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	precision;
	int	sharp;
	int	space;
	int	plus;
}				t_listf;

/*---------------Base---------------------*/

int		ft_printf(const char *s, ...);
int		ft_printf_flag(char *str, va_list args);
int		ft_check_plus(char c, va_list format, t_listf flags);

/*---------------Flags---------------------*/

t_listf	ft_init_flaglist(void);
t_listf	ft_flag_left(t_listf flags);
int		ft_manage_flags(const char *str, int i, t_listf *flags);
int		ft_is_flags(int c);
int		ft_is_speci(int c);
int		ft_is_flag(int c);

/*---------------Manage c---------------------*/

int		ft_putchar_p(char c);
int		ft_putchar_pf(char c, t_listf flags);

/*---------------Manage s---------------------*/

int		ft_putstr_p(char *str);
int		ft_putstr_pf(const char *str, t_listf flags);
int		ft_putstr_left(const char *str, t_listf flags);
int		ft_putstr_preci(const char *str, int precis);

/*---------------Manage d & i---------------------*/

int		ft_putnbr_p(int n);
int		ft_putnbr_pf(int n, t_listf flags);
int		ft_manage_nbr(char *new, int n, t_listf flags);
int		ft_manage_pms_nbr(int n, t_listf *flags);
int		ft_manage_pms_precis(char *new, int n, t_listf flags);
char	*ft_itoan(long n, char *new, size_t len);
char	*ft_short_itoan(long n);
size_t	ft_itoanlen(long n);

/*---------------Manage p---------------------*/

int		ft_putptr_pf(unsigned long int n, t_listf flags);
int		ft_manage_adress(unsigned long int n);
int		ft_ptrlen(unsigned long int n);
void	ft_put_adress(unsigned long int n);

/*---------------Manage u---------------------*/

int		ft_putunsigned(unsigned n, t_listf flags);
int		ft_manage_unsigned(char *new, t_listf flags);
int		ft_manage_unsigned_precis(char *new, t_listf flags);
char	*ft_utoa(unsigned int n, char *str, size_t len);
char	*ft_short_utoa(unsigned int n);
size_t	ft_utoalen(long n);

/*---------------Manage ux & X---------------------*/

int		ft_puthex(unsigned int n, int ucase, t_listf flags);
int		ft_manage_hex_precis(char *new, int n, int ucase, t_listf flags);
int		ft_manage_hex(char *new, int n, int ucase, t_listf flags);
char	*ft_xtoa(unsigned long int n, char *str, size_t len);
char	*ft_short_xtoa(unsigned int n, int ucase);
size_t	ft_xtoalen(long n);

/*---------------Utils---------------------*/

int		ft_strlen_i(const char *str);
int		ft_manage_width(int width, int size, int zero);
int		ft_manage_precision(const char *str, int i, t_listf *flags);
int		ft_manage_sharp(int ucase);
t_listf	ft_manage_digit(char c, t_listf flags);

#endif
