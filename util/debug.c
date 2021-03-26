/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:07:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 19:03:24 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

long	ps_memcpy(char buf[], long i, char *str)
{
	long	size;

	size = ft_strlen(str);
	ft_memcpy(buf + i, str, size);
	return (size);
}

long	ps_spacecpy(char buf[], long i, long len)
{
	long	j;

	j = -1;
	while (++j < len)
		i += ps_memcpy(buf, i, " ");
	return (len);
}

long	ps_nbrcpy(char buf[], long i, long n)
{
	long	size;
	char	*str;

	if (!(str = ft_itoa(n)))
		exit (ps_error());
	ps_memcpy(buf, i, str);
	size = ft_strlen(str);
	free(str);
	return (size);
}

/*
**  17 + 1 + 17 + 1 + 8 + 1 = 45
**  --------A-------- --------B-------- -NEXT-  \n
*/

void	stack_memcpy(t_dlst *a, t_ps *ps, char buf[], long *i)
{
	long	j;

	j = *i;
	*i += ps_memcpy(buf, *i, "[");
	*i += ps_nbrcpy(buf, *i, a->value);
	*i += ps_memcpy(buf, *i, "]");
	*i += ps_nbrcpy(buf, *i, ps->def[a->value]);
	*i += ps_spacecpy(buf, *i, STACK_WIDTH - (*i - j));
}

void	put_turn(char buf[], long *i, long val)
{
	char	tmp[8];
	long	j;
	long	div;

	j = -1;
	while (++j < 7)
		tmp[j] = ' ';
	tmp[7] = 0;
	j = 0;
	div = 10000;
	while (++j < 6)
	{
		if (val / div)
			tmp[j] = val / div + '0';
		val %= div;
		div /= 10;
	}
	*i += ps_memcpy(buf, *i, tmp);
}

void	put_info(char buf[], long *i, t_ps *ps, long height)
{
	if (height == 1 && ps->cflag)
	{
		*i += ps_memcpy(buf, *i, GREEN);
		*i += ps_memcpy(buf, *i, ps->ans_next[height - 1]);
		*i += ps_memcpy(buf, *i, WHITE);
	}
	else if (height <= 5)
		*i += ps_memcpy(buf, *i, ps->ans_next[height - 1]);
	else if (height == 7)
		*i += ps_memcpy(buf, *i, "-TURN-  ");
	else if (height == 8)
		put_turn(buf, i, ps->ans_turn);
	else if (height == 9)
		*i += ps_memcpy(buf, *i, " ----- ");
	else if (height == 10)
		put_turn(buf, i, ps->ans_result);
	else
		*i += ps_spacecpy(buf, *i, INFO_WIDTH);
}

void	debug(t_dlst *a, t_dlst *b, t_ps *ps)
{
	t_dlst	*ta;
	t_dlst	*tb;
	char	buf[100000];
	long	i;
	long	height;

	ta = a->next;
	tb = b->next;
	ft_putstr_fd(CLEAR, 2);
	i = 0;
	i += ps_memcpy(buf, i, "--------A-------- --------B-------- -NEXT-  \n");
	height = 0;
	while (++height < TURNMAX)
	{
		if (ta->value != -1)
			stack_memcpy(ta, ps, buf, &i);
		else
			i += ps_spacecpy(buf, i, STACK_WIDTH);
		if (tb->value != -1)
			stack_memcpy(tb, ps, buf, &i);
		else
			i += ps_spacecpy(buf, i, STACK_WIDTH);
		put_info(buf, &i, ps, height);
		if (ta->value != -1)
			ta = ta->next;
		if (tb->value != -1)
			tb = tb->next;
		i += ps_memcpy(buf, i, "\n");
	}
	buf[i] = 0;
	ft_putstr_fd(buf, 2);
	sleep(1);
}

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
	ft_putstr_fd(CLEAR, 2);
	dlst_clear(vps->ans);
	free(vps);
	dlst_clear(a);
	dlst_clear(b);
}
