/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:48:22 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/24 23:43:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	atoi_sort(long argc, char **argv, t_ps *ps)
{
	//argvをint化して、ps->nにいれて、
	long	i;

	i = -1;
	while (++i < argc - 1)
	{
		ps->n[i].value = ps_atoi(*argv);
		ps->n[i].id = i;
	}
}

// Convert id
// ps->nはmapみたいな構造
// dlstにはidを入れる

long	ps_atoi(char *str)
{
	long	n;
	long	num;
	long	m;

	n = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	m = 0;
	while (ft_isdigit(*str))
	{
		num = (*str++ - '0');
		m = m * 10 + n * num;
		if (m > INT_MAX || m < INT_MIN)
			exit(ps_error());
	}
	if (*str)
		exit(ps_error());
	return (m);
}

void	ps_value_init(t_ps *ps, char **argv)
{
	long	i;
	char	**strs;
	
	strs = argv + 1;
	i = -1;
	while(++i < ps->size)
	{
		ps->n[i].id = i;
		ps->n[i].value = ps_atoi(*strs);
		strs++;
	}
}

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
	while (i < j)
	{
		while (n[++i].value < n[pivot].value)
			;
		while (n[pivot].value < n[--j].value)
			;
		if (i < j)
			ps_swap(&n[i], &n[j]);
	}
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
void	value_dup_check(t_ps *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit (ps_error());
	}
}

void	convert_val_to_id(t_ps *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size)
	{
		ps->def[i] = ps->n[i].value;
		ps->n[i].value = i;
	}
}

/*
**  ---ps_value_init---
**  n[0] = (55, 0)
**  n[1] = (23, 1)
**  n[2] = (87, 2)
**  ---quick_sort(value)---
**  n[0] = (23, 1)
**  n[1] = (55, 0)
**  n[2] = (87, 2)
**	---convert_val_to_id---
**  n[0] = (0, 1) def[0] = 23
**  n[1] = (1, 0) def[1] = 55
**  n[2] = (2, 2) def[2] = 87
**  ---quick_sort(id)---
**  n[0] = (1, 0)
**  n[1] = (0, 1)
**  n[2] = (2, 2)
**  ---t_dlst *a---
**  a[0] = 1 <-55
**  a[1] = 0 <-23
**  a[2] = 2 <-87
*/

t_ps *ps_init(long argc, char **argv)
{
	t_ps *ps;

	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		exit (ps_error());
	ps->awant = 0;
	ps->bwant = 0;
	ps->ans = dlst_def();
	ps->size = argc - 1;
	ps_value_init(ps, argv);
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	value_dup_check(ps);
	convert_val_to_id(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_ID);
	return (ps);
}
