/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:30:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/31 15:17:51 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./util.h"

/*
**  sort
*/

bool	avoid_check(long command, t_allsort *t);
bool	disturb_check(t_dlst *a, long command, t_allsort *t);
void	ans_update(long turn, t_allsort *t);
void	allsort(t_dlst *a, t_dlst *b, t_ps *ps, long size);
void	ansjoin(t_ps *ps, t_allsort *t);
void	dlst_update_ans(t_dlst *a, t_dlst *b, t_allsort *t);
void	half_set(t_dlst *a, t_dlst *b, t_ps *ps);
void	a_dfs(t_dlst *a, t_dlst *b, t_allsort *t, long turn);
void	a_settle_top(t_dlst *a, t_dlst *b, t_allsort *t, long turn);

/*
**  push_swap
*/

void	push_swap(long argc, char **argv);
void	allsort_less7(t_dlst *a, t_dlst *b, t_ps *ps);
void	sort_over6(t_dlst *a, t_dlst *b, t_ps *ps);
void	ans_trance_longcut(t_dlst *ans);
void	ans_remove_redo(t_dlst *ans);
#endif
