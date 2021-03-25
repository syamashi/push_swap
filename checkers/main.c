/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:36:15 by syamashi          #+#    #+#             */
/*   Updated: 2021/03/25 12:07:33 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || argc > ARGLIMIT)
		exit(ps_error());
	else
		checker(argc, argv);
	return (0);
}
