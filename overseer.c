/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:51:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/26 14:56:32 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	check_each_philo(t_philos *philo)
{
	if (((time_ms(philo->data->start_time) - philo->last_meal)
			> philo->data->time_die))
	{
		ft_print(philo, "died.");
		philo->data->died = 1;
		return (-1);
	}
	if (philo->data->times_to_eat != -1
		&& philo->times_eaten == philo->data->times_to_eat)
	{
		philo->data->meals_completed++;
	}
	if (philo->data->times_to_eat != -1 && philo->data->meals_completed
		== philo->data->nbr_philos)
	{
		printf("All the Philosophers ate.");
		philo->data->all_ate = 1;
		return (-1);
	}
	return (0);
}

void	overseer(t_data *data)
{
	int			i;
	t_philos	*tmp;

	while (1)
	{
		i = 0;
		data->meals_completed = 1;
		while (i < data->nbr_philos)
		{
			tmp = &data->philos[i];
			if (check_each_philo(tmp) == -1)
				return ;
			i++;
		}
	}
}
