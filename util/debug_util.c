/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:33:16 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 22:44:58 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

long	ps_memcpy(char buf[], long i, char *str)
{
	long	size;

	size = ft_strlen(str);
	ft_memcpy(buf + i, str, size);
	return (size);
}

long	ps_spacecpy(char buf[], long i, long len)
{
	long	j;

	j = -1;
	while (++j < len)
		i += ps_memcpy(buf, i, " ");
	return (len);
}

long	ps_nbrcpy(char buf[], long i, long n)
{
	long	size;
	char	*str;

	if (!(str = ft_itoa(n)))
		exit(ps_error());
	ps_memcpy(buf, i, str);
	size = ft_strlen(str);
	free(str);
	return (size);
}

void	inversion_print(char buf[], long *i, char *str)
{
	*i += ps_memcpy(buf, *i, INVERSION);
	*i += ps_memcpy(buf, *i, EMPHASIZE);
	*i += ps_memcpy(buf, *i, str);
	*i += ps_memcpy(buf, *i, DEFSET);
}

void	color_print(char buf[], long *i, char *str, char *color)
{
	*i += ps_memcpy(buf, *i, color);
	*i += ps_memcpy(buf, *i, str);
	*i += ps_memcpy(buf, *i, DEFCOLOR);
}
