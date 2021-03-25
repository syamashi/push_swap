/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:56:29 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 14:10:02 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	dlst_size(t_dlst *b)
{
	long	size;
	t_dlst	*tmp;

	size = 0;
	tmp = b->next;
	while (tmp->value != -1)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
