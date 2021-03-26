/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:25:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/27 08:23:20 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

bool	option_handler(char c, t_ps *ps)
{
	if (c == 'v')
		ps->vflag = true;
	else if (c == 'c')
		ps->cflag = true;
	else if (ft_isdigit(c))
		return (true);
	else
		exit(ps_error());
	return (false);
}

char	**get_option(long *argc, char **argv, t_ps *ps)
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
			if (option_handler((*strs)[i], ps))
				return (argv);
		}
		if (i == 1)
			exit(ps_error());
		argv++;
		strs = argv + 1;
		(*argc)--;
	}
	return (argv);
}
