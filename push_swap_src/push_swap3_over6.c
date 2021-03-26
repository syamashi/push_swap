/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:58:34 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 10:39:53 by syamashi         ###   ########.fr       */
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
		if (b->prev->value == ps->bwant - i - 1)
			rra_addans(b, ps, RRB);
		if (b->next->value == ps->bwant - i - 1)
			pa_addans(a, b, ps, PA);
		if (a->next->value != ps->bwant-1-i)
			exit(printf("[b_settle_top] Error\n"));
	}
	while (a->next->value == ps->awant)
	{
		ra_addans(a, ps, RA);
		ps->awant++;
	}
}

void	b_quick_sort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	long	i;
	long	pivot;
	long	b_size;
	long	a_addsize;

	i = -1;
	b_size = size;
	a_addsize = 0;
	pivot = ps->awant + (size - 1) / 2;
	// bのsizeが5以下ならソートに回す？
	while (++i < size && b_size > SORTSIZE && a_addsize < size / 2)
	{
		if (b->next->value == ps->awant)
		{
			pa_addans(a, b, ps, PA);
			ra_addans(a, ps, RA);
			ps->awant++;
			ps->bwant = ps->awant;
			b_size--;
		}
		else if (b->next->value > pivot)
		{
			pa_addans(a, b, ps, PA);
			b_size--;
			a_addsize++;
		}
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
		if (b->prev->value == ps->awant)
			rra_addans(b, ps, RRB);
		if (b->next->next->value == ps->awant)
			sa_addans(b, ps, SB);
		if (b->next->value == ps->awant)
		{
			pa_addans(a, b, ps, PA);
			i--;
		}
		if (a->next->next->value == ps->awant && a->next->value == ps->awant + 1)
			sa_addans(a, ps, SA);
		if (a->next->value == ps->awant)
		{
			ra_addans(a, ps, RA);
			++ps->awant;
			i++;
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
