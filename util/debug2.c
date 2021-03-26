/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:32:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 22:44:53 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	stack_memcpy(t_dlst *a, t_ps *ps, char buf[], long *i)
{
	long	j;

	j = *i;
	*i += ps_memcpy(buf, *i, "[");
	*i += ps_nbrcpy(buf, *i, a->value);
	*i += ps_memcpy(buf, *i, "]");
	*i += ps_nbrcpy(buf, *i, ps->def[a->value]);
	*i += ps_spacecpy(buf, *i, STACK_WIDTH - (*i - j));
}

void	put_turn(char buf[], long *i, long val)
{
	char	tmp[8];
	long	j;
	long	div;
	bool	zero;

	j = -1;
	while (++j < 7)
		tmp[j] = ' ';
	tmp[7] = 0;
	j = 0;
	div = 10000;
	zero = false;
	while (++j < 6)
	{
		if (val / div || j == 5)
			zero = true;
		if (zero)
			tmp[j] = val / div + '0';
		val %= div;
		div /= 10;
	}
	*i += ps_memcpy(buf, *i, tmp);
}

void	put_info(char buf[], long *i, t_ps *ps, long height)
{
	if (height == 1 && ps->cflag)
		color_print(buf, i, ps->ans_next[height - 1], GREEN);
	else if (height <= 5)
		*i += ps_memcpy(buf, *i, ps->ans_next[height - 1]);
	else if (height == 8)
	{
		if (ps->cflag)
			inversion_print(buf, i, "--TURN--");
		else
			*i += ps_memcpy(buf, *i, "--TURN--");
	}
	else if (height == 9)
		put_turn(buf, i, ps->ans_turn);
	else if (height == 10)
		*i += ps_memcpy(buf, *i, " ----- ");
	else if (height == 11)
		put_turn(buf, i, ps->ans_result);
	else
		*i += ps_spacecpy(buf, *i, INFO_WIDTH);
}
