/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:39:24 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/06 17:13:27 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_philosophers(t_data *data, char **argv)
{
	ft_check_all_args(argv);
	data->philos = ft_mini_atoi(argv[1]);
	data->time_to_die = ft_mini_atoi(argv[2]);
	data->time_to_eat = ft_mini_atoi(argv[3]);
	data->time_to_sleep = ft_mini_atoi(argv[4]);
	if (argv[5])
		data->number_of_times_eaten = ft_mini_atoi(argv[5]);
	else
		data->number_of_times_eaten = -1;
	if (data->philos > 0)
		ft_create_table(data);
	data->run = 0;
	data->value = 0;
	data->start_time = ft_time();
}

void	ft_start_program(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data->philos);
	i = 0;
	while (i < data->philos)
	{
		philos[i] = ft_struct_philo(data, i);
		i++;
	}
	i = 0;
	while (i < data->philos)
	{
		philos[i].right_fork = philos[(i + 1) % data->philos].left_fork;
		if (pthread_create(&philos[i].thread, NULL, ft_table, &philos[i]) != 0)
		{
			printf("Error creating thread\n");
			return ;
		}
		i++;
	}
	ft_death(philos, data);
	ft_cleanup(philos);
}
