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

void	overseer(t_data *data)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (1)
	{
		if (data->last_meal == 1)
		{
			break ;
		}

//		while (i < data->nbr_philos)
//		{
//			if (data->philos[i].times_eaten < data->times_to_eat)
//				check = 0;
//			i++;
//		}
//		if (check == 1)
//			break ;
	}
}
