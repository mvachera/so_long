/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:35:22 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/20 16:36:30 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg(va_list arg, char c)
{
	if (c == 'c')
		return (ft_charactere(arg));
	if (c == 's')
		return (ft_string(arg));
	if (c == 'p')
		return (ft_pointeur(arg));
	if (c == 'd' || c == 'i')
		return (ft_int(arg));
	if (c == 'u')
		return (ft_unsigned(arg));
	if (c == 'x')
		return (ft_hexa_min(arg));
	if (c == 'X')
		return (ft_hexa_maj(arg));
	if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_search_arg(arg, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
