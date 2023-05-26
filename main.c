/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:45:20 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/26 17:04:38 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	get_values(char **argv, t_args *args)
{
	if (ft_atoi(argv[1]) > 0 && ft_atoi(argv[2]) > 0
		&& ft_atoi(argv[3]) > 0 && ft_atoi(argv[4]) > 0)
	{
		args->nbr_philos = ft_atoi(argv[1]);
		args->time_die = ft_atoi(argv[2]);
		args->time_eat = ft_atoi(argv[3]);
		args->time_sleep = ft_atoi(argv[4]);
		if (argv[5])
			args->times_to_eat = ft_atoi(argv[5]);
		if (args->times_to_eat <= 0)
			return (-1);
		if (!argv[5])
			args->times_to_eat = -1;
	}
	else
		return (-1);
	return (0);
}


int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 5 || argc == 6)
	{
		if (get_values(argv, &args) == -1)
		{
			printf("Wrong type of arguments");
			return (-1);
		}
		printf("nbr_philos = %d\n", args.nbr_philos);
		printf("time_die = %d\n", args.time_die);
		printf("time_eat = %d\n", args.time_eat);
		printf("time_sleep = %d\n", args.time_sleep);
		printf("times_to_eat = %d\n", args.times_to_eat);
	}
}
