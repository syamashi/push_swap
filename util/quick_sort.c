/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:17:41 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 22:54:09 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	ps_swap(t_pair *a, t_pair *b)
{
	long	tmp_id;
	long	tmp_value;

	tmp_id = a->id;
	tmp_value = a->value;
	a->id = b->id;
	a->value = b->value;
	b->id = tmp_id;
	b->value = tmp_value;
}

/*
**  array{3, 4, 1, 2, 5}, pivot = n[0] = 3;
**  [1.search]
**  3 >4 1 2< 5
**
**  [2.swap(i, j)]
**  3 (2) 1 (4) 5
**
**  [3.search]
**  (3) 2 (1<) >4 5
**
**  [4.swap(p, j)]
**  (1) 2 (3) 4 5
*/

long	partition_value(t_pair n[], long left, long right)
{
	long	i;
	long	j;
	long	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	printf("i,j,piv:%ld %ld %ld\n", i, j, pivot);
	while (i < j)
	{
		while (i < j && n[++i].value < n[pivot].value)
			;
		while (j && n[pivot].value < n[--j].value)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
	printf("[aft]i,j,piv:%ld %ld %ld\n", i, j, pivot);
	ps_swap(&n[pivot], &n[j]);
	return (j);
}

long	partition_id(t_pair n[], long left, long right)
{
	long	i;
	long	j;
	long	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (n[++i].id < n[pivot].id)
			;
		while (n[pivot].id < n[--j].id)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
	ps_swap(&n[pivot], &n[j]);
	return (j);
}

void	quick_sort(t_pair n[], long left, long right, long flag)
{
	long	pivot;

	printf("left:%ld right:%ld pivot:%ld\n", left, right, pivot);
	if (left < right)
	{
		if (flag == SORT_VALUE)
			pivot = partition_value(n, left, right);
		if (flag == SORT_ID)
			pivot = partition_id(n, left, right);
		quick_sort(n, left, pivot - 1, flag);
		quick_sort(n, pivot + 1, right, flag);
	}
}
