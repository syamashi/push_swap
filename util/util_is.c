/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:05:34 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 09:16:18 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	is_sorted(t_dlst *a)
{
	t_dlst	*dlst;

	dlst = a;
	while (dlst->next->value != -1)
	{
		if (dlst->value > dlst->next->value)
			return (false);
		dlst = dlst->next;
	}
	return (true);
}
