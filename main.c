/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:45:20 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/29 11:44:36 by ccosta-c         ###   ########.fr       */
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
		if (args->times_to_eat <= 0)
			return (-1);
		if (!argv[5])
			args->times_to_eat = -1;
	}
	else
		return (-1);
	return (0);
}

int	initialize(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philos) * data->nbr_philos);
	if (!data->philos)
		return (-1);
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		 
	}
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].times_eaten = 0;
		i++;
	}
	i = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (get_values(argv, &data) == -1 || initialize(&data) == -1)
		{
			printf("Wrong type of arguments\n");
			return (-1);
		}
	}
}
