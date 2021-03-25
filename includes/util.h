/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:38:11 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 10:59:36 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
# include "../libft/libft.h"

#define STDERR 2
#define ARGLIMIT 1001
#define SORTLIMIT 12
#define SORTSIZE 4
#define SA 0
#define SB 1
#define SS 2
#define PA 3
#define PB 4
#define RA 5
#define RB 6
#define RR 7
#define RRA 8
#define RRB 9
#define RRR 10

typedef	struct	s_dlst
{
	long			value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

typedef	struct	s_pair
{
	long	value;
	long	id;
}				t_pair;

typedef	struct	s_ps
{
	t_dlst	*ans;
	t_pair	n[ARGLIMIT + 10];
	long	def[ARGLIMIT + 10];
	long	size;
	long	awant;
	long	bwant;
}				t_ps;

typedef struct	s_allsort
{
	long	max_turn;
	long	turn;
	long	tmp[SORTLIMIT + 10];
	long	ans[SORTLIMIT + 10];
	long	pre;
	long	awant;
	long	size;
	long	fin;
}				t_allsort;

/*
**  debug
*/
void	debug(t_dlst *a, t_dlst *b, t_ps *ps);

/*
**  all_free
*/

void	dlst_clear(t_dlst *a);

/*
**  push_swap
*/

/*
**  commands
*/

bool	sa(t_dlst *a);
bool	pa(t_dlst *a, t_dlst *b);
bool	ra(t_dlst *a);
bool	rra(t_dlst *a);
bool	rr(t_dlst *a, t_dlst *b);
bool	rrr(t_dlst *a, t_dlst *b);
void	dlst_addback(t_dlst *dlst, long value);
t_dlst	*dlst_def(void);
bool	sa_addans(t_dlst *a, t_ps *ps, long command);
bool	pa_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command);
bool	ra_addans(t_dlst *a, t_ps *ps, long command);
bool	rra_addans(t_dlst *a, t_ps *ps, long command);
bool	rr_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command);
bool	rrr_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command);

/*
**  others
*/

t_dlst	*make_dlst(t_ps *ps);
long	ps_error();
long	ps_atoi(char *str);
bool	is_sorted(t_dlst *a);
#endif
