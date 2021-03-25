/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:16:37 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 00:13:15 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	rr(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || ra(a) || ra(b));
}

bool	rrr(t_dlst *a, t_dlst *b)
{
	return (b->next->next->value == -1 || rra(a) || rra(b));
}
