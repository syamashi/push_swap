/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:57:51 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/24 17:36:07 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**
*/

int	main(int argc, char **argv)
{
	fflush(stdout); setbuf(stdout,NULL);
	if (argc == 1 || argc > ARGLIMIT)
		exit(ps_error());
	else
		push_swap(argc, argv);
	return (0);
}
