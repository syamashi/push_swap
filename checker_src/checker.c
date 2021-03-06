/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:06:33 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/31 12:45:42 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

long	get_command(char *line)
{
	if (!(ft_strncmp("sa", line, 3)))
		return (SA);
	if (!(ft_strncmp("sb", line, 3)))
		return (SB);
	if (!(ft_strncmp("ss", line, 3)))
		return (SS);
	if (!(ft_strncmp("pa", line, 3)))
		return (PA);
	if (!(ft_strncmp("pb", line, 3)))
		return (PB);
	if (!(ft_strncmp("ra", line, 3)))
		return (RA);
	if (!(ft_strncmp("rb", line, 3)))
		return (RB);
	if (!(ft_strncmp("rr", line, 3)))
		return (RR);
	if (!(ft_strncmp("rra", line, 4)))
		return (RRA);
	if (!(ft_strncmp("rrb", line, 4)))
		return (RRB);
	if (!(ft_strncmp("rrr", line, 4)))
		return (RRR);
	exit(ps_error());
}

void	print_judge(t_dlst *a, t_dlst *b)
{
	if (is_sorted(a) && b->next->value == -1)
	{
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd("OK", 1);
		ft_putstr_fd(DEFCOLOR, 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd(RED, 1);
		ft_putstr_fd("KO", 1);
		ft_putstr_fd(DEFCOLOR, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	line_handler(t_dlst *a, t_dlst *b, char *line, t_ps *ps)
{
	print_sleep(50);
	if (*line)
	{
		change_dlst(a, b, get_command(line), true);
		ps->ans_turn++;
		if (ps->vflag)
			debug(a, b, ps);
	}
	free(line);
}

void	checker(int argc, char **argv)
{
	char	*line;
	long	ret;
	t_ps	*ps;
	t_dlst	*a;
	t_dlst	*b;

	ps = ps_init(argc, argv);
	a = make_dlst(ps);
	b = dlst_def();
	if (a->next->value == -1)
		return (all_free(a, b, ps));
	if (ps->vflag)
		debug(a, b, ps);
	while ((ret = get_next_line(0, &line)) >= 0)
	{
		line_handler(a, b, line, ps);
		if (!ret)
			break ;
	}
	if (ret < 0)
		exit(ps_error());
	print_judge(a, b);
	all_free(a, b, ps);
}
