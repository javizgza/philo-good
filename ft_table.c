/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:08:00 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/06 17:01:27 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_check_meals(t_philo *philo)
{
    if (philo->data->number_of_times_eaten != -1 \
    && philo->times_eaten == philo->data->number_of_times_eaten)
    {
        philo->data->run++;
        if (philo->data->run == philo->data->philos)
            exit(0);
    }
}

void    *ft_table(void   *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    ft_step(philo);
    while (philo->data->value != 1)
    {
        ft_order(philo);
        ft_print(philo, "has taken a fork");
        ft_print(philo, "has taken a fork");
        philo->last_meal_time = ft_time();
        ft_print(philo, "is eating");
        philo->times_eaten++;
        ft_wait(philo->data->time_to_eat);
        ft_unlock(philo);
        ft_check_meals(philo);
        ft_print(philo, "is sleeping");
        ft_wait(philo->data->time_to_sleep);
        ft_print(philo, "is thinking");
    }
    return (NULL);
}
