/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over6_util2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:12:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/31 16:26:52 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	bwant_keep(t_dlst *b, t_ps *ps, long b_size)
{
	ps->bwant++;
	if (b_size == 1)
		return (true);
	if (b->prev->value == ps->bwant)
		ps->bwant++;
	ra_addans(b, ps, RB);
	return (false);
}

bool	bwant_left(t_dlst *b, t_ps *ps)
{
	t_dlst	*tmp;
	long	begin;

	begin = b->value;
	tmp = b->next;
	while (tmp->value != begin)
	{
		if (tmp->value == ps->bwant)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	half_set(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	i;
	long	b_size;

	i = -1;
	b_size = 0;
	while (++i < ps->size && b_size < ps->size / 2)
	{
		while (b->next->value == ps->bwant)
			if (bwant_keep(b, ps, b_size))
				break ;
		if (b->next->value == ps->bwant + 1 && !bwant_left(b, ps) && b_size > 1)
			ra_addans(b, ps, RB);
		if (a->next->value < (ps->size / 2))
		{
			pa_addans(b, a, ps, PB);
			b_size++;
		}
		else
			ra_addans(a, ps, RA);
	}
}
