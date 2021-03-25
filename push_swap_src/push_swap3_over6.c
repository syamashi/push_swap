/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:58:34 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 01:32:59 by syamashi         ###   ########.fr       */
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
//	printf("[search_a_size] size:%ld\n", size);
//	sleep(1);
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
		while (b->next->value == ps->awant)
		{
			pa_addans(a, b, ps, PA);
			ra_addans(a, ps, RA);
			ps->awant++;
			ps->bwant = ps->awant;
			i++;
		}
		if (b->next->value > (ps->awant + (size - i) / 2))
			pa_addans(a, b, ps, PA);
		else
			ra_addans(b, ps, RB);
	}
}

void	a_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;
	
	i = 0;
//	printf("[a_quick_sort]%ld\n", size);
//	sleep(1);
	while (i < size)
	{
	//	debug(a, b, ps);
	//	printf("[a_quick_sort]\n");
	//	sleep(1);
		if (b->next->value == ps->awant)
		{
			pa_addans(a, b, ps, PA);
			ra_addans(a, ps, RA);
			ps->bwant = ++ps->awant;
		}
		else if (a->next->value == ps->awant)
		{
			i++;
			ra_addans(a, ps, RA);
			ps->bwant = ++ps->awant;
		}
		else if (a->next->next->value == ps->awant && a->next->value == ps->awant + 1)
		{
			sa_addans(a, ps, SA);
			ra_addans(a, ps, RA);
			ra_addans(a, ps, RA);
			i += 2;
		}
		else
		{	
			pa_addans(b, a, ps, PB);
			i++;
		}
	}
}

void	sort_over6(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	size;

	half_set(a, b, ps);
	while (ps->awant != ps->size)
	{
//		debug(a, b, ps);
//		printf("start\n");
//		sleep(1);
		b_settle_top(a, b, ps);
//		debug(a, b, ps);
//		printf("b_settle\n");
//		sleep(1);
		while ((size = dlst_size(b)) > SORTSIZE)
			b_quick_sort(a, b, ps, size);
//		debug(a, b, ps);
//		printf("b_quick\n");
//		sleep(1);
		if (size)
			allsort(a, b, ps, size);
//		debug(a, b, ps);
//		printf("b_allsort\n");
//		sleep(1);
		while ((size = search_a_size(a, ps)) && size <= SORTSIZE)
			allsort(a, b, ps, size);
//		debug(a, b, ps);
//		printf("a_allsort\n");
//		sleep(1);
		if (size)
			a_quick_sort(a, b, ps, size);
//		debug(a, b, ps);
//		printf("end\n");
//		sleep(1);
	}
}
