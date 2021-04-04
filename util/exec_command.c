/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:33:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/04/04 11:42:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

long	recover(long command)
{
	if (command == PA)
		return (PB);
	if (command == PB)
		return (PA);
	if (command == RA)
		return (RRA);
	if (command == RB)
		return (RRB);
	if (command == RR)
		return (RRR);
	if (command == RRA)
		return (RA);
	if (command == RRB)
		return (RB);
	if (command == RRR)
		return (RR);
	return (command);
}

bool	change_dlst(t_dlst *a, t_dlst *b, long command, bool exec)
{
	if (!exec)
		command = recover(command);
	if (command == SA)
		return (sa(a));
	if (command == SB)
		return (sa(b));
	if (command == SS)
		return (ss_stop(a, b));
	if (command == PA)
		return (pa(a, b));
	if (command == PB)
		return (pa(b, a));
	if (command == RA)
		return (ra(a));
	if (command == RB)
		return (ra(b));
	if (command == RR)
		return (rr_stop(a, b));
	if (command == RRA)
		return (rra(a));
	if (command == RRB)
		return (rra(b));
	if (command == RRR)
		return (rrr_stop(a, b));
	return (true);
}
