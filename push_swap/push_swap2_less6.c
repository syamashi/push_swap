/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2_less6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:39:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 11:04:29 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dfs(t_dlst *a, t_dlst *b, t_allsort *t, long turn)
{
	long	command;

	if (turn >= t->max_turn)
		return ;
	if (b->next->value == -1 && is_sorted(a))
		return(ans_update(turn, t));
	command = -1;
	while (++command < 11)
	{
		if (avoid_check(command, t) || turn >= t->max_turn)
			continue;
		if (change_dlst(a, b, command, true))
			continue;
		t->pre = command;
		t->tmp[turn] = command;
		dfs(a, b, t, turn + 1);
		change_dlst(a, b, command, false);
	}
}

void	allsort_less6(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_allsort	t;
	long		i;

	t.max_turn = SORTLIMIT;
	i = -1;
	while (++i < SORTLIMIT)
	{
		t.tmp[i] = -1;
		t.ans[i] = -1;
	}
	t.pre = -1;
	dfs(a, b, &t, 0);
	ansjoin(ps, &t);
	dlst_update_ans(a, b, &t);
}
