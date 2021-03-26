/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:19:14 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 22:20:35 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	init_ansinfo2(t_ps *vps, t_dlst *tmp, long i)
{
	if (tmp->value == RR)
		ft_memcpy(vps->ans_next[i], "  RR   ", 8);
	if (tmp->value == RRB)
		ft_memcpy(vps->ans_next[i], " RRA   ", 8);
	if (tmp->value == RRB)
		ft_memcpy(vps->ans_next[i], " RRB   ", 8);
	if (tmp->value == RRR)
		ft_memcpy(vps->ans_next[i], " RRR   ", 8);
	if (tmp->value == -1)
		ft_memcpy(vps->ans_next[i], "       ", 8);
}

void	init_ansinfo(t_ps *vps, t_dlst *ans, long i)
{
	t_dlst	*tmp;

	tmp = ans;
	while (++i < 5)
	{
		if (tmp->value == PA)
			ft_memcpy(vps->ans_next[i], "  PA   ", 8);
		else if (tmp->value == PB)
			ft_memcpy(vps->ans_next[i], "  PB   ", 8);
		else if (tmp->value == SA)
			ft_memcpy(vps->ans_next[i], "  SA   ", 8);
		else if (tmp->value == SB)
			ft_memcpy(vps->ans_next[i], "  SB   ", 8);
		else if (tmp->value == SS)
			ft_memcpy(vps->ans_next[i], "  SS   ", 8);
		else if (tmp->value == RA)
			ft_memcpy(vps->ans_next[i], "  RA   ", 8);
		else if (tmp->value == RB)
			ft_memcpy(vps->ans_next[i], "  RB   ", 8);
		else
			init_ansinfo2(vps, tmp, i);
		if (tmp->value != -1)
			tmp = tmp->next;
	}
}

void	print_operation(t_dlst *a, t_dlst *b, t_ps *vps, t_dlst *ans)
{
	init_ansinfo(vps, ans, -1);
	debug(a, b, vps);
	change_dlst(a, b, ans->value, true);
	vps->ans_turn++;
}

void	ans_visualize(int argc, char **argv, t_ps *ps)
{
	t_ps	*vps;
	t_dlst	*a;
	t_dlst	*b;
	t_dlst	*ans;

	vps = ps_init(argc, argv);
	a = make_dlst(vps);
	b = dlst_def();
	vps->ans_result = dlst_size(ps->ans);
	vps->ans_turn = 0;
	ans = ps->ans->next;
	while (ans->value != -1)
	{
		print_operation(a, b, vps, ans);
		ans = ans->next;
	}
	init_ansinfo(vps, ans, -1);
	debug(a, b, vps);
	dlst_clear(vps->ans);
	free(vps);
	dlst_clear(a);
	dlst_clear(b);
}
