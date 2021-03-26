/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:41:27 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 23:24:00 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	all_free(t_dlst *a, t_dlst *b, t_ps *ps)
{
	dlst_clear(ps->ans);
	free(ps);
	dlst_clear(a);
	dlst_clear(b);
}

void	dlst_clear(t_dlst *a)
{
	t_dlst	*tmp;

	a->prev->next = NULL;
	while (a)
	{
		tmp = a->next;
		a->prev = NULL;
		free(a);
		a = tmp;
	}
}
