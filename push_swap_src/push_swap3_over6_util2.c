/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3_over6_util2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:12:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 12:39:05 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	half_set(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	i;
	long	b_size;

	i = -1;
	b_size = 0;
	while (++i < ps->size && b_size < ps->size / 2)
	{
		while (b->next->value == ps->bwant)
		{
			ps->bwant++;
			if (b_size == 1)
				break ;
			ra_addans(b, ps, RB);
		}
		if (a->next->value < (ps->size / 2))
		{
			pa_addans(b, a, ps, PB);
			b_size++;
		}
		else
			ra_addans(a, ps, RA);
	}
}
