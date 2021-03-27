/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4_removedup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:37:04 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 16:54:53 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if (tmp->value == SA && tmp->next->value == SA)
			dlst_delone(tmp, RR);
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

void	ans_trance_dup(t_dlst *ans)
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
