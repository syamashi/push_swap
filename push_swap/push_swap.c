/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:02:14 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 10:54:40 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ps_error(void)
{
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}

void	putans(t_dlst *ans)
{
	t_dlst	*tmp;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		if (tmp->value == SA)
			write(1, "sa\n", 3);
		if (tmp->value == SB)
			write(1, "sb\n", 3);
		if (tmp->value == SS)
			write(1, "ss\n", 3);
		if (tmp->value == PA)
			write(1, "pa\n", 3);
		if (tmp->value == PB)
			write(1, "pb\n", 3);
		if (tmp->value == RA)
			write(1, "ra\n", 3);
		if (tmp->value == RB)
			write(1, "rb\n", 3);
		if (tmp->value == RR)
			write(1, "rr\n", 3);
		if (tmp->value == RRA)
			write(1, "rra\n", 4);
		if (tmp->value == RRB)
			write(1, "rrb\n", 4);
		if (tmp->value == RRR)
			write(1, "rrr\n", 4);
		tmp = tmp->next;
	}
}

void	push_swap(long argc, char **argv)
{
	t_ps		*ps;
	t_dlst		*a;
	t_dlst		*b;

	ps = ps_init(argc, argv);
	a = make_dlst(ps);
	b = dlst_def();
	if (ps->size <= 6)
		allsort_less6(a, b, ps);
	else
		sort_over7(a, b, ps);
	putans(ps->ans);
	debug(a, b, ps);
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}
