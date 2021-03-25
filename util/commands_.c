/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:24:26 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 00:14:12 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	sa(t_dlst *a)
{
	t_dlst	*atmp1;
	t_dlst	*atmp2;
	t_dlst	*atmp3;

	if (a->next->next->value == -1)
		return (true);
	atmp1 = a->next;
	atmp2 = a->next->next;
	atmp3 = a->next->next->next;
	a->next = atmp2;
	atmp2->next = atmp1;
	atmp1->next = atmp3;
	atmp3->prev = atmp1;
	atmp1->prev = atmp2;
	atmp2->prev = a;
	return (false);
}

bool	pa(t_dlst *a, t_dlst *b)
{
	t_dlst	*atmp1;
	t_dlst	*btmp1;
	t_dlst	*btmp2;

	if (b->next->value == -1)
		return (true);
	atmp1 = a->next;
	btmp1 = b->next;
	btmp2 = b->next->next;
	b->next = btmp2;
	btmp2->prev = b;
	a->next = btmp1;
	btmp1->next = atmp1;
	atmp1->prev = btmp1;
	btmp1->prev = a;
	return (false);
}

bool	ra(t_dlst *a)
{
	t_dlst	*atmp1;
	t_dlst	*atmp2;
	t_dlst	*atmp3;

	if (a->next->next->value == -1)
		return (true);
	atmp1 = a->prev;
	atmp2 = a->next;
	atmp3 = a->next->next;
	a->next = atmp3;
	atmp3->prev = a;
	a->prev = atmp2;
	atmp2->prev = atmp1;
	atmp1->next = atmp2;
	atmp2->next = a;
	return (false);
}

bool	rra(t_dlst *a)
{
	t_dlst	*atmp1;
	t_dlst	*atmp2;
	t_dlst	*atmp3;

	if (a->next->next->value == -1)
		return (true);
	atmp1 = a->prev->prev;
	atmp2 = a->prev;
	atmp3 = a->next;
	a->next = atmp2;
	atmp2->next = atmp3;
	atmp3->prev = atmp2;
	atmp2->prev = a;
	a->prev = atmp1;
	atmp1->next = a;
	return (false);
}
