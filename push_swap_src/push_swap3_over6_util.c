/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over6_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:39:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 16:23:02 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	allsort_a_settle_top(t_dlst *a, t_dlst *b, t_allsort *t, long turn)
{
	long	command;

	command = RA;
	ra(a);
	t->pre = command;
	t->tmp[turn] = command;
	t->awant++;
	a_dfs(a, b, t, turn + 1);
	t->awant--;
	rra(a);
	return ;
}

void	allsort_b_settle_top(t_dlst *a, t_dlst *b, t_allsort *t, long turn)
{
	pa(a, b);
	t->tmp[turn] = PA;
	a_dfs(a, b, t, turn + 1);
	pa(b, a);
	return ;
}

void	a_dfs(t_dlst *a, t_dlst *b, t_allsort *t, long turn)
{
	long	command;

	if (turn >= t->max_turn - (t->fin - t->awant))
		return ;
	if (t->fin == 98)
	{
		ft_putstr_fd("turn:", 2);
		ft_putnbr_fd(turn, 2);
		ft_putstr_fd(" t->awant:", 2);
		ft_putnbr_fd(t->awant, 2);
		ft_putstr_fd("\n", 2);
	}
	if (t->awant == t->fin && b->next->value == -1)
		return (ans_update(turn, t));
	if (a->next->value == t->awant)
		return (allsort_a_settle_top(a, b, t, turn));
	if (b->next->value == t->awant)
		return (allsort_b_settle_top(a, b, t, turn));
	command = -1;
	while (++command < 11)
	{
		if (avoid_check(command, t) || turn >= t->max_turn - 1)
			continue;
		if (disturb_check(a, b, command, t))
			continue;
		if (change_dlst(a, b, command, true))
			continue;
		t->pre = command;
		t->tmp[turn] = command;
		a_dfs(a, b, t, turn + 1);
		change_dlst(a, b, command, false);
	}
}

long	fin_b_search(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_dlst	*tmpb;
	long	ret;

	ret = ps->awant;
	while (1)
	{
		tmpb = b->next;
		while (ret != tmpb->value && tmpb->value != -1)
			tmpb = tmpb->next;
		if (a->next->value != ret &&
			a->next->next->value != ret &&
			tmpb->value != ret)
			return (ret);
		ret++;
	}
}

void	allsort(t_dlst *a, t_dlst *b, t_ps *ps, long size)
{
	t_allsort	t;
	long		i;

	t.max_turn = SORTLIMIT_OVER6;
	i = -1;
	while (++i < SORTLIMIT_OVER6)
	{
		t.tmp[i] = -1;
		t.ans[i] = -1;
	}
	t.pre = ps->ans->prev->value;
	t.size = size;
	t.awant = ps->awant;
	if (b->next->value != -1)
		t.fin = fin_b_search(a, b, ps);
	else
		t.fin = size + ps->awant;
	ft_putstr_fd("t.fin:",2);
	ft_putnbr_fd(t.fin,2);
	ft_putstr_fd("\n",2);
	a_dfs(a, b, &t, 0);
	ansjoin(ps, &t);
	dlst_update_ans(a, b, &t);
	ps->awant = t.fin;
	ps->bwant = t.fin;
}
