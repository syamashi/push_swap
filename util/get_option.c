/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:25:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/26 19:04:02 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	get_option(long *argc, char **argv, t_ps *ps)
{
	char	**strs;
	long	i;

	ps->vflag = false;
	ps->cflag = false;
	strs = argv + 1;
	while (*strs && **strs == '-')
	{
		i = 0;
		while ((*strs)[++i])
		{
			if ((*strs)[i] == 'v')
				ps->vflag = true;
			else if ((*strs)[i] == 'c')
				ps->cflag = true;
			else
				exit(ps_error());
		}
		argv++;
		strs = argv + 1;
		(*argc)--;
	}
}
