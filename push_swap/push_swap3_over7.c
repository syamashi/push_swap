/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:58:34 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 11:04:45 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**  最初に半分に分ける。方向はra
*/

void	half_set(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size)
	{
		if (b->next->value == ps->bwant)
		{
			ps->bwant++;
			ra_addans(b, ps, RB);
		}
		if (a->next->value < (ps->size / 2))
			pa_addans(b, a, ps, PB);
		else
			ra_addans(a, ps, RA);
	}
}

long	dlst_size(t_dlst *b)
{
	long	size;
	t_dlst	*tmp;

	size = 0;
	tmp = b->next;
	while (tmp->value != -1)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

// max-min = lenになるまで
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

void	sort_over7(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	size;
	long	i;

	half_set(a, b, ps);
	while (ps->awant != ps->size)
	{
		debug(a, b, ps);
		// bが進んでるなら、aに還元
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
		debug(a, b, ps);
		while ((size = dlst_size(b)) > SORTSIZE)
		{
			i = -1;
			while (++i < size)
			{
				// もしawantがきたら、pa
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
		if (size)
			allsort(a, b, ps, size);
		debug(a, b, ps);
		while ((size = search_a_size(a, ps)) && size <= SORTSIZE)
		{
			allsort(a, b, ps, size); // a全探索で収納
		}
		// 0じゃなければ、Bに分割
		debug(a, b, ps);
		if (size)
		{
			i = -1;
			while (++i < size)
			{
				// もしawantがきたら、ra
				// もしawantがbにきたら、pa ra
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
				// Bにawantがあるか探索してもいいかも？
				else
					pa_addans(b, a, ps, PB);
			}
		}
	}
}
