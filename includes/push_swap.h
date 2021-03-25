/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:30:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 10:58:12 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSG_SWAP_H
# define PUSH_SWAP_H

# include "./util.h"
#define SORT_VALUE 0
#define SORT_ID 1

/*
**  sort
*/

bool	avoid_check(long command, t_allsort *t);
bool	disturb_check(t_dlst *a, t_dlst *b, long command, t_allsort *t);
bool	change_dlst(t_dlst *a, t_dlst *b, long command, bool exec);
long	recover(long command);
void	ans_update(long turn, t_allsort *t);
void	allsort(t_dlst *a, t_dlst *b, t_ps *ps, long size);
void	ansjoin(t_ps *ps, t_allsort *t);
void	dlst_update_ans(t_dlst *a, t_dlst *b, t_allsort *t);

/*
**  push_swap
*/

void	push_swap(long argc, char **argv);
t_ps	*ps_init(long argc, char **argv);
void	allsort_less6(t_dlst *a, t_dlst *b, t_ps *ps);
void	sort_over7(t_dlst *a, t_dlst *b, t_ps *ps);
#endif
