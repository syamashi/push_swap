/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:02:14 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 08:53:38 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command_putout(long command)
{
	if (command == SA)
		write(1, "sa", 2);
	if (command == SB)
		write(1, "sb", 2);
	if (command == SS)
		write(1, "ss", 2);
	if (command == PA)
		write(1, "pa", 2);
	if (command == PB)
		write(1, "pb", 2);
	if (command == RA)
		write(1, "ra", 2);
	if (command == RB)
		write(1, "rb", 2);
	if (command == RR)
		write(1, "rr", 2);
	if (command == RRA)
		write(1, "rra", 3);
	if (command == RRB)
		write(1, "rrb", 3);
	if (command == RRR)
		write(1, "rrr", 3);
}

void	ans_print(t_dlst *ans)
{
	t_dlst	*tmp;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		command_putout(tmp->value);
		tmp = tmp->next;
		ft_putstr_fd("\n", 1);
	}
}

void	dlst_replace(t_dlst *ans, long command)
{
	t_dlst	*tmp2;

	tmp2 = ans->next->next;
	free(ans->next);
	ans->next = NULL;
	ans->value = command;
	ans->next = tmp2;
	tmp2->prev = ans;
}

void	ans_remove_dup(t_dlst *ans)
{
	t_dlst	*tmp;

	tmp = ans->next;
	while (tmp->value != -1)
	{
		if (tmp->value == RA && tmp->next->value == RB)
			dlst_replace(tmp, RR);
		if (tmp->value == RB && tmp->next->value == RA)
			dlst_replace(tmp, RR);
		if (tmp->value == RRA && tmp->next->value == RRB)
			dlst_replace(tmp, RR);
		if (tmp->value == RRB && tmp->next->value == RRA)
			dlst_replace(tmp, RRR);
		if (tmp->value == SA && tmp->next->value == SB)
			dlst_replace(tmp, SS);
		if (tmp->value == SB && tmp->next->value == SA)
			dlst_replace(tmp, SS);
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
	ans_remove_dup(ps->ans);
	if (ps->vflag)
		ans_visualize(argc, argv, ps);
	ans_print(ps->ans);
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}
