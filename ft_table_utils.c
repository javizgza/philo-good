/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:11:18 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/06 17:22:37 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_died(t_philo *philo)
{
    ft_print(philo, "died");
    philo->data->value = 1;
    exit(0);
}

void    ft_print(t_philo *philo, char *print)
{
    long long rel_time;

    rel_time = ft_time() - philo->data->start_time;
    pthread_mutex_lock(philo->print);
    printf("%lld %d %s\n", rel_time, philo->id + 1, print);
    pthread_mutex_unlock(philo->print);
}

void    ft_order(t_philo *philo)
{
    if (philo->id & 1)
    {
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
    }
}

void    ft_unlock(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    ft_step(t_philo *philo)
{
    philo->start_time = ft_time();
    philo->last_meal_time = philo->start_time;
    if (philo->id % 2 == 1)  // Add a small delay for odd philosophers
        usleep(150);
    if (philo->data->philos == 1)
        ft_wait(philo->data->time_to_die);
}