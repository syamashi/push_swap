/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:38:11 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 17:29:11 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define STDERR 2
# define ARGLIMIT 1001
# define SORTLIMIT_LESS7 12
# define SORTLIMIT_OVER6 30
# define SORTSIZE 4
# define SORT_VALUE 0
# define SORT_ID 1
# define PA 0
# define PB 1
# define SA 2
# define SB 3
# define SS 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define STACK_WIDTH 18
# define INFO_WIDTH 8
# define CLEAR "\033[2J"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define DEFCOLOR "\033[39m"
# define BLACK "\033[30m"
# define INVERSION "\033[7m"
# define DEFSET "\033[0m"
# define EMPHASIZE "\033[1m"
# define WHITE_BACK "\033[47m"
# define DEFCOLOR_BACK "\033[49m"
# define TURNMAX 41

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
	long	ans_result;
	long	ans_turn;
	char	ans_next[5][10];
	bool	vflag;
	bool	cflag;
}				t_ps;

typedef struct	s_allsort
{
	long	max_turn;
	long	turn;
	long	tmp[SORTLIMIT_OVER6 + 10];
	long	ans[SORTLIMIT_OVER6 + 10];
	long	pre;
	long	awant;
	long	size;
	long	fin;
}				t_allsort;

/*
**  debug
*/

void			debug(t_dlst *a, t_dlst *b, t_ps *ps);
void			ans_visualize(int argc, char **argv, t_ps *ps);
long			ps_memcpy(char buf[], long i, char *str);
long			ps_spacecpy(char buf[], long i, long len);
long			ps_nbrcpy(char buf[], long i, long n);
void			inversion_print(char buf[], long *i, char *str);
void			color_print(char buf[], long *i, char *str, char *color);
void			put_info(char buf[], long *i, t_ps *ps, long height);
void			put_turn(char buf[], long *i, long val);
void			stack_memcpy(t_dlst *a, t_ps *ps, char buf[], long *i);
void			print_sleep(long k);

/*
**  all_free
*/

void			all_free(t_dlst *a, t_dlst *b, t_ps *ps);
void			dlst_clear(t_dlst *a);

/*
**  init
*/

t_ps			*ps_init(long argc, char **argv);
void			quick_sort(t_pair n[], long left, long right, long flag);

/*
**  exec
*/

bool			change_dlst(t_dlst *a, t_dlst *b, long command, bool exec);
long			recover(long command);

/*
**  commands
*/

bool			sa(t_dlst *a);
bool			pa(t_dlst *a, t_dlst *b);
bool			ra(t_dlst *a);
bool			rra(t_dlst *a);
bool			rr(t_dlst *a, t_dlst *b);
bool			rrr(t_dlst *a, t_dlst *b);
void			dlst_addback(t_dlst *dlst, long value);
t_dlst			*dlst_def(void);
bool			sa_addans(t_dlst *a, t_ps *ps, long command);
bool			pa_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command);
bool			ra_addans(t_dlst *a, t_ps *ps, long command);
bool			rra_addans(t_dlst *a, t_ps *ps, long command);
bool			rr_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command);
bool			rrr_addans(t_dlst *a, t_dlst *b, t_ps *ps, long command);

/*
**  others
*/

t_dlst			*make_dlst(t_ps *ps);
long			ps_error();
long			ps_atoi(char *str);
bool			is_sorted(t_dlst *a);
long			dlst_size(t_dlst *b);
char			**get_option(long *argc, char **argv, t_ps *ps);
#endif
