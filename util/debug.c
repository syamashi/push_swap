/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:07:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 00:16:14 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	print_header(char buf[], long *i, t_ps *ps)
{
	if (ps->cflag)
	{
		inversion_print(buf, i, "----------A--------+--------B---------+");
		inversion_print(buf, i, "-NEXT-");
		*i += ps_memcpy(buf, *i, " ");
	}
	else
	{
		*i += ps_memcpy(buf, *i, "----------A--------+--------B---------+");
		*i += ps_memcpy(buf, *i, "-NEXT-");
	}
	*i += ps_memcpy(buf, *i, "\n");
}

void	print_sleep(long k)
{
	long	i;

	i = -1;
	while (++i < k)
		ft_putstr_fd("", 2);
}

void	print_stack(t_dlst *dlst, t_ps *ps, char buf[], long *i)
{
	*i += ps_memcpy(buf, *i, "|");
	if (dlst->value != -1)
		stack_memcpy(dlst, ps, buf, i);
	else
		*i += ps_spacecpy(buf, *i, STACK_WIDTH);
}

void	prompt_dlst(t_dlst **ta, t_dlst **tb)
{
	if ((*ta)->value != -1)
		(*ta) = (*ta)->next;
	if ((*tb)->value != -1)
		(*tb) = (*tb)->next;
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
	print_header(buf, &i, ps);
	height = 0;
	while (++height < TURNMAX)
	{
		print_stack(ta, ps, buf, &i);
		print_stack(tb, ps, buf, &i);
		i += ps_memcpy(buf, i, "|");
		put_info(buf, &i, ps, height);
		prompt_dlst(&ta, &tb);
		i += ps_memcpy(buf, i, "\n");
	}
	i += ps_memcpy(buf, i, "-------------------+-------------------\n");
	buf[i] = 0;
	ft_putstr_fd(buf, 2);
	print_sleep(500000);
}
