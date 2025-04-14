/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:41:17 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/04 22:45:44 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_num(void)
{
	write(2, "Error in num of philos.\n", 24);
	return (1);
}

int	ft_check_all_args(char **argv)
{
	if (ft_mini_atoi(argv[1]) <= 0 || ft_check_if_num(argv[1]) == 1)
		return (ft_error_num());
	if (ft_mini_atoi(argv[2]) <= 0 || ft_check_if_num(argv[2]) == 1)
	{
		write(2, "Error in time to die.\n", 23);
		return (1);
	}
	if (ft_mini_atoi(argv[3]) <= 0 || ft_check_if_num(argv[3]) == 1)
	{
		write(2, "Error in time to eat.\n", 23);
		return (1);
	}
	if (ft_mini_atoi(argv[4]) <= 0 || ft_check_if_num(argv[4]) == 1)
	{
		write(2, "Error in time to sleep.\n", 25);
		return (1);
	}
	if (argv[5] && (ft_mini_atoi(argv[5]) <= 0 \
		|| ft_check_if_num(argv[5]) == 1))
	{
		write(2, "Error in number os meals for each philo.\n", 41);
		return (1);
	}
	return (0);
}

int	ft_check_if_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_mini_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res);
}
