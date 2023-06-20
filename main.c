/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:45:20 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/20 15:52:58 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	get_values(char **argv, t_data *args)
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
		if (!argv[5])
			args->times_to_eat = -1;
	}
	else
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (get_values(argv, &data) == -1)
		{
			printf("Wrong type of arguments\n");
			return (-1);
		}
		if (initialize(&data) == -1)
			return (-1);
	}
}
