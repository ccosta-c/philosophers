/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:51:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/22 12:54:07 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int     check_each_philo(t_philos *philo)
{
    if (((time_ms(philo->data->start_time) - philo->last_meal ) > philo->data->time_die))
    {
        ft_print(philo, "died.");
        return (-1);
    }
    return (0);
}

void	overseer(t_data *data)
{
    int i;
    t_philos *tmp;

    while (1)
    {
        i = 0;
        while (i < data->nbr_philos) {
            tmp = &data->philos[i];
            if (check_each_philo(tmp) == -1)
                return;
            i++;
        }
    }
}