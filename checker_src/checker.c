/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:06:33 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 14:07:41 by syamashi         ###   ########.fr       */
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

void	checker(int argc, char **argv)
{
	char	*line;
	long	ret;
	long	command;
	t_ps	*ps;
	t_dlst	*a;
	t_dlst	*b;

	ps = ps_init(argc, argv);
	a = make_dlst(ps);
	b = dlst_def();
	while ((ret = get_next_line(0, &line)) == 1)
	{
		command = get_command(line);
		change_dlst(a, b, command, true);
		free(line);
	}
	if (ret < 0)
		exit(ps_error());
	if (is_sorted(a) && b->next->value == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}
