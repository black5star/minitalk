/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:17:00 by hboustaj          #+#    #+#             */
/*   Updated: 2024/04/05 03:39:25 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char	*str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

void	signal_sender(int pid, char *str, int len)
{
	int	i;
	int	bits;

	i = 0;
	while (i <= len)
	{
		bits = 0;
		while (bits < 8)
		{
			if ((str[i] >> bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(STDOUT_FILENO, "Error : check the number of argument.\n", 39);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0 || pid == -1)
		exit(1);
	signal_sender(pid, argv[2], ft_strlen(argv[2]));
	return (0);
}
