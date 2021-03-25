/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_add2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:16:37 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 00:14:54 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	rr_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command)
{
	if (b->next->next->value == -1 || ra(a) || ra(b))
		return (true);
	dlst_addback(ps->ans, command);
	return (false);
}

bool	rrr_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command)
{
	if (b->next->next->value == -1 || rra(a) || rra(b))
		return (true);
	dlst_addback(ps->ans, command);
	return (false);
}
