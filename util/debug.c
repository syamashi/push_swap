/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:07:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 11:40:08 by syamashi         ###   ########.fr       */
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
		exit (ps_error());
	ps_memcpy(buf, i, str);
	size = ft_strlen(str);
	free(str);
	return (size);
}

/*
**  17 + 1 + 17 + 1 + 6 + 1 = 43
**  --------A-------- --------B-------- -NEXT-\n
*/

void	debug(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_dlst	*ta;
	t_dlst	*tb;
	char	buf[100000];
	long	i;
	long	j;

	ta = a->next;
	tb = b->next;
//	ft_putstr_fd(CLEAR, 1);
	i = 0;
	i += ps_memcpy(buf, i, "--------A-------- --------B-------- -NEXT-\n");
	while (ta->value != -1 || tb->value != -1)
	{
		if (ta->value != -1)
		{
			j = i;
			i += ps_memcpy(buf, i, "[");
			i += ps_nbrcpy(buf, i, ta->value);
			i += ps_memcpy(buf, i, "]");
			i += ps_nbrcpy(buf, i, ps->def[ta->value]);
			i += ps_spacecpy(buf, i, STACK_WIDTH - (i - j));
		}
		else
			i += ps_spacecpy(buf, i, STACK_WIDTH);
		if (tb->value != -1)
		{
			j = i;
			i += ps_memcpy(buf, i, "[");
			i += ps_nbrcpy(buf, i, tb->value);
			i += ps_memcpy(buf, i, "]");
			i += ps_nbrcpy(buf, i, ps->def[tb->value]);
			i += ps_spacecpy(buf, i, STACK_WIDTH - (i - j));
		}
		else
			i += ps_spacecpy(buf, i, STACK_WIDTH);
		if (ta->value != -1)
			ta = ta->next;
		if (tb->value != -1)
			tb = tb->next;
		i += ps_memcpy(buf, i, "\n");
	}
	buf[i] = 0;
	write(1, buf, i);
}
