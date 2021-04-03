/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:16:37 by syamashi          #+#    #+#             */
/*   Updated: 2021/04/03 15:28:14 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	rr(t_dlst *a, t_dlst *b)
{
	bool	exec;

	exec = false;
	exec |= ra(a);
	exec |= ra(b);
	return (exec);
}

bool	rrr(t_dlst *a, t_dlst *b)
{
	bool	exec;

	exec = false;
	exec |= rra(a);
	exec |= rra(b);
	return (exec);
}

bool	ss(t_dlst *a, t_dlst *b)
{
	bool	exec;

	exec = false;
	exec |= sa(a);
	exec |= sa(b);
	return (exec);
}
