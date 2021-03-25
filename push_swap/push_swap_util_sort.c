/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:03:17 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 11:03:57 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ans_update(long turn, t_allsort *t)
{
	long	i;

	t->max_turn = turn;
	i = -1;
	while (++i < turn)
		t->ans[i] = t->tmp[i];
	i = -1;
	while (++i < turn)
	{
		if (t->tmp[i] == SA)
			write(1, "sa ", 3);
		if (t->tmp[i] == SB)
			write(1, "sb ", 3);
		if (t->tmp[i] == SS)
			write(1, "ss ", 3);
		if (t->tmp[i] == PA)
			write(1, "pa ", 3);
		if (t->tmp[i] == PB)
			write(1, "pb ", 3);
		if (t->tmp[i] == RA)
			write(1, "ra ", 3);
		if (t->tmp[i] == RB)
			write(1, "rb ", 3);
		if (t->tmp[i] == RR)
			write(1, "rr ", 3);
		if (t->tmp[i] == RRA)
			write(1, "rra ", 4);
		if (t->tmp[i] == RRB)
			write(1, "rrb ", 4);
		if (t->tmp[i] == RRR)
			write(1, "rrr", 4);
	}
	write(1, "\n", 1);
}

long	recover(long command)
{
	if (command == PA)
		return (PB);
	if (command == PB)
		return (PA);
	if (command == RA)
		return (RRA);
	if (command == RB)
		return (RRB);
	if (command == RR)
		return (RRR);
	if (command == RRA)
		return (RA);
	if (command == RRB)
		return (RB);
	if (command == RRR)
		return (RR);
	return (command);
}

bool	change_dlst(t_dlst *a, t_dlst *b, long command, bool exec)
{
	if (!exec)
		command = recover(command);
	if (command == SA)
		return (sa(a));
	if (command == SB)
		return (sa(b));
	if (command == SS)
		return (b->next->next->value == -1 || sa(a) || sa(b));
	if (command == PA)
		return (pa(a, b));
	if (command == PB)
		return (pa(b, a));
	if (command == RA)
		return (ra(a));
	if (command == RB)
		return (ra(b));
	if (command == RR)
		return (b->next->next->value == -1 || ra(a) || ra(b));
	if (command == RRA)
		return (rra(a));
	if (command == RRB)
		return (rra(b));
	if (command == RRR)
		return (b->next->next->value == -1 || rra(a) || rra(b));
	return (true);
}

bool	avoid_check(long command, t_allsort *t)
{
	if (command == SA && (t->pre == SA || t->pre == SB || t->pre == SS))
		return (true);
	if (command == SB && (t->pre == SA || t->pre == SB || t->pre == SS))
		return (true);
	if (command == SS && (t->pre == SA || t->pre == SB || t->pre == SS))
		return (true);
	if (command == PA && (t->pre == PB))
		return (true);
	if (command == PB && (t->pre == PA))
		return (true);
	if (command == RA && (t->pre == RRA || t->pre == RRR || t->pre == RB))
		return (true);
	if (command == RB && (t->pre == RRB || t->pre == RRR || t->pre == RA))
		return (true);
	if (command == RR && (t->pre == RRA || t->pre == RRB || t->pre == RRR))
		return (true);
	if (command == RRA && (t->pre == RA || t->pre == RR || t->pre == RRB))
		return (true);
	if (command == RRB && (t->pre == RB || t->pre == RR || t->pre == RRA))
		return (true);
	if (command == RRR && (t->pre == RA || t->pre == RB || t->pre == RR))
		return (true);
	return (false);
}

bool	disturb_check(t_dlst *a, t_dlst *b, long command, t_allsort *t)
{
	if (command == SA && (a->next->next->value >= t->fin))
		return (true);
	if (command == SB && (b->next->next->value >= t->fin))
		return (true);
	if (command == SS && (a->next->next->value >= t->fin
	|| b->next->next->value >= t->fin))
		return (true);
	if (command == PA && (a->next->value >= t->fin))
		return (true);
	if (command == PB && (b->next->value >= t->fin))
		return (true);
	if (command == RA && (a->next->value >= t->fin))
		return (true);
	if (command == RB && (b->next->value >= t->fin))
		return (true);
	if (command == RR && (a->next->value >= t->fin || b->next->value >= t->fin))
		return (true);
	if (command == RRA && (a->prev->value < t->awant))
		return (true);
	if (command == RRB && (b->prev->value < t->awant))
		return (true);
	if (command == RRR && (a->prev->value < t->awant || b->prev->value < t->awant))
		return (true);
	return (false);
}

void	ansjoin(t_ps *ps, t_allsort *t)
{
	long	i;

	i = -1;
	while (++i < t->max_turn)
		dlst_addback(ps->ans, t->ans[i]);
}

void	dlst_update_ans(t_dlst *a, t_dlst *b, t_allsort *t)
{
	long	i;

	i = -1;
	while (++i < t->max_turn)
		change_dlst(a, b, t->ans[i], true);
}
