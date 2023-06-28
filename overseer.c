/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:51:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/28 17:47:09 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	check_each_philo(t_philos *philo)
{
	if (((get_time() - philo->last_meal)
			> philo->data->time_die))
	{
		ft_print(philo, "died.");
		pthread_mutex_lock(&philo->data->verify);
		philo->data->died = 1;
		pthread_mutex_unlock(&philo->data->verify);
		return (-1);
	}
	if (philo->data->times_to_eat != -1
		&& philo->times_eaten >= philo->data->times_to_eat)
		philo->data->meals_completed++;
	if (philo->data->times_to_eat != -1 && philo->data->meals_completed
		== philo->data->nbr_philos)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("All the Philosophers ate.\n");
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->verify);
		philo->data->all_ate = 1;
		pthread_mutex_unlock(&philo->data->verify);
		return (-1);
	}
	return (0);
}

void	*overseer(void *data)
{
	int			i;
	t_data		*tmp;

	tmp = (t_data *)data;
	while (1)
	{
		i = 0;
		tmp->meals_completed = 1;
		while (i < tmp->nbr_philos)
		{
			if (check_each_philo(&tmp->philos[i]) == -1)
				return (NULL);
			i++;
		}
	}
}
