/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:06:13 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/06 17:30:06 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_create_table(t_data *data)
{
    int i;

    i = 0;
    data->print = malloc(sizeof(pthread_mutex_t));
    if (!data->print)
        write(2, "Error creating mutex\n", 23);
    if (pthread_mutex_init(data->print, NULL) != 0)
        write(2, "Error creating  mutex \n", 25);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philos);
    if (!data->forks)
        write(2, "Error creating forks\n", 23);
    while (i < data->philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            write(2, "Error creating forks\n", 23);
        i++;
    }
}

void    ft_death(t_philo *philos, t_data *data)
{
    int i;

    ft_wait(1);
    while (data->value != 1)
    {
        i = 0;
        while (i < data->philos)
        {
            if (ft_time() - philos[i].last_meal_time > data->time_to_die)
                ft_died(&philos[i]);
            if (philos[i].times_eaten >= data->number_of_times_eaten \
                && data->number_of_times_eaten != -1)
            i++;
        }
    }
}

t_philo    ft_struct_philo(t_data *data, int who)
{
    t_philo philo;
    philo.print = data->print;
    philo.philos = data->philos;
    philo.id = who;
    philo.left_fork = &data->forks[who];
    philo.stop = 0;
    philo.times_eaten = 0;
    philo.data = data;
    return (philo);
}