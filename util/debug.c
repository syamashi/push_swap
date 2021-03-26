/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:07:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 14:32:28 by syamashi         ###   ########.fr       */
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
**  17 + 1 + 17 + 1 + 6 + 1 = 43
**  --------A-------- --------B-------- -NEXT-\n
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

void	put_info(t_dlst *ans)
{
	ft_putstr_fd("\033[2;37H", 2); /* カーソルを移動 */
	ft_putnbr_fd(ans->value, 2);
	ft_putstr_fd("\033[3;37H", 2); /* カーソルを移動 */
	ft_putstr_fd("\033[4;37H", 2); /* カーソルを移動 */
	ft_putstr_fd("\033[5;37H", 2); /* カーソルを移動 */
	ft_putstr_fd("\033[6;37H", 2); /* カーソルを移動 */
}

void	debug(t_dlst *a, t_dlst *b, t_ps *ps, t_dlst *ans)
{
	t_dlst	*ta;
	t_dlst	*tb;
	char	buf[100000];
	long	i;
	long	turn;

	ta = a->next;
	tb = b->next;
	ft_putstr_fd(CLEAR, 2);
	i = 0;
	i += ps_memcpy(buf, i, "--------A-------- --------B-------- -NEXT-\n");
	turn = -1;
	while (++turn < TURNMAX)
	{
		if (ta->value != -1)
			stack_memcpy(ta, ps, buf, &i);
		else
			i += ps_spacecpy(buf, i, STACK_WIDTH);
		if (tb->value != -1)
			stack_memcpy(tb, ps, buf, &i);
		else
			i += ps_spacecpy(buf, i, STACK_WIDTH);
		if (ta->value != -1)
			ta = ta->next;
		if (tb->value != -1)
			tb = tb->next;
		i += ps_memcpy(buf, i, "\n");
	}
	buf[i] = 0;
	ft_putstr_fd(buf, 2);
	put_info(ans);
	sleep(1);
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
	debug(a, b, vps, ans);
	while (ans->value != -1)
	{
		change_dlst(a, b, ans->value, true);
		debug(a, b, vps, ans);
		ans = ans->next;
		vps->ans_turn++;
	}
	dlst_clear(vps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}
