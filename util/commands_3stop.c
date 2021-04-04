/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3stop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:16:37 by syamashi          #+#    #+#             */
/*   Updated: 2021/04/04 11:41:55 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	rr_stop(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || ra(a) || ra(b));
}

bool	rrr_stop(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || rra(a) || rra(b));
}

bool	ss_stop(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || sa(a) || sa(b));
}
