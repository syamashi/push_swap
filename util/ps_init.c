/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:48:22 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 08:58:02 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (++i < ps->size)
	{
		ps->n[i].id = i;
		ps->n[i].value = ps_atoi(*strs);
		strs++;
	}
	--i;
	while (++i < ARGLIMIT)
	{
		ps->n[i].id = i;
		ps->n[i].value = 0;
	}
}

void	value_dup_check(t_ps *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(ps_error());
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

t_ps	*ps_init(long argc, char **argv)
{
	t_ps	*ps;
	long	i;

	if (!(ps = (t_ps *)malloc(sizeof(t_ps))))
		exit(ps_error());
	argv = get_option(&argc, argv, ps);
	ps->awant = 0;
	ps->bwant = 0;
	ps->ans = dlst_def();
	ps->size = argc - 1;
	i = -1;
	while (++i < 5)
		ft_memcpy(ps->ans_next[i], "\0", 8);
	ps->ans_result = 0;
	ps->ans_turn = 0;
	ps_value_init(ps, argv);
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	value_dup_check(ps);
	convert_val_to_id(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_ID);
	return (ps);
}
