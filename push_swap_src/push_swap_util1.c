/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:03:17 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 16:26:11 by syamashi         ###   ########.fr       */
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
	if (command == RA && (t->pre == RRA || t->pre == RRR))
		return (true);
	if (command == RB && (t->pre == RRB || t->pre == RRR))
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
	if (command == SS && (a->next->next->value >= t->fin ||
	b->next->next->value >= t->fin))
		return (true);
	if (command == RA && (a->next->value >= t->fin))
		return (true);
	if (command == RR && (a->next->value >= t->fin || b->next->value >= t->fin))
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
