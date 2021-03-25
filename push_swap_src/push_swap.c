/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:02:14 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 15:40:27 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command_putout(long command)
{
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	if (command == SS)
		write(1, "ss\n", 3);
	if (command == PA)
		write(1, "pa\n", 3);
	if (command == PB)
		write(1, "pb\n", 3);
	if (command == RA)
		write(1, "ra\n", 3);
	if (command == RB)
		write(1, "rb\n", 3);
	if (command == RR)
		write(1, "rr\n", 3);
	if (command == RRA)
		write(1, "rra\n", 4);
	if (command == RRB)
		write(1, "rrb\n", 4);
	if (command == RRR)
		write(1, "rrr\n", 4);
}

void	ans_print(t_dlst *ans)
{
	t_dlst	*tmp;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		command_putout(tmp->value);
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
	if (ps->size < 7)
		allsort_less7(a, b, ps);
	else
		sort_over6(a, b, ps);
	ans_print(ps->ans);
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}
