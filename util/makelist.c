/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:46:36 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 00:20:15 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	dlst_addback(t_dlst *dlst, long value)
{
	t_dlst	*new;
	t_dlst	*ptmp;

	if (!(new = (t_dlst *)malloc(sizeof(t_dlst))))
		exit(ps_error());
	new->value = value;
	ptmp = dlst->prev;
	ptmp->next = new;
	new->next = dlst;
	dlst->prev = new;
	new->prev = ptmp;
}

t_dlst	*dlst_def(void)
{
	t_dlst	*dlst;

	if (!(dlst = (t_dlst *)malloc(sizeof(t_dlst))))
		exit(ps_error());
	dlst->value = -1;
	dlst->next = dlst;
	dlst->prev = dlst;
	return (dlst);
}

t_dlst	*make_dlst(t_ps *ps)
{
	t_dlst	*dlst;
	long	i;

	dlst = dlst_def();
	i = -1;
	while (++i < ps->size)
		dlst_addback(dlst, ps->n[i].value);
	return (dlst);
}
