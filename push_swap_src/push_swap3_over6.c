/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:58:34 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 17:33:01 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	search_a_size(t_dlst *a, t_ps *ps)
{
	long	size;
	long	max;
	t_dlst	*tmp;

	size = 0;
	max = -ARGLIMIT;
	tmp = a->next;
	while (max - ps->awant + 1 != size && tmp->value)
	{
		size++;
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (size);
}

void	b_settle_top(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	i;

	i = -1;
	while (++i + ps->awant < ps->bwant)
	{
		rra_addans(b, ps, RRB);
		pa_addans(a, b, ps, PA);
	}
	while (ps->awant < ps->bwant)
	{
		ra_addans(a, ps, RA);
		ps->awant++;
	}
}

void	b_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;

	i = -1;
	while (++i < size)
	{
		if (b->next->value == ps->awant)
		{
			pa_addans(a, b, ps, PA);
			ra_addans(a, ps, RA);
			ps->awant++;
			ps->bwant = ps->awant;
		}
		else
			ra_addans(b, ps, RB);
	}
}

void	a_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;
	
	i = -1;
	while (++i < size)
	{
		if (b->next->value == ps->awant)
		{
			pa_addans(a, b, ps, PA);
			ra_addans(a, ps, RA);
			ps->awant++;
			ps->bwant = ps->awant;
		}
		if (a->next->value == ps->awant)
		{
			ra_addans(a, ps, RA);
			ps->awant++;
			ps->bwant = ps->awant;
		}
		else
			pa_addans(b, a, ps, PB);
	}
}

void	sort_over6(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	size;

	half_set(a, b, ps);
	while (ps->awant != ps->size)
	{
		b_settle_top(a, b, ps);
		while ((size = dlst_size(b)) > SORTSIZE)
			b_quick_sort(a, b, ps, size);
		if (size)
			allsort(a, b, ps, size);
		while ((size = search_a_size(a, ps)) && size <= SORTSIZE)
			allsort(a, b, ps, size);
		if (size)
			a_quick_sort(a, b, ps, size);
	}
}
