/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:17:03 by hboustaj          #+#    #+#             */
/*   Updated: 2024/04/17 19:01:41 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((n + 48), fd);
}

void	signal_handler(int num, siginfo_t *siginfo, void *ucontext)
{
	static char	c;
	static int	i;

	(void)ucontext;
	if (num == SIGUSR1)
		c = c + (1 << i);
	i++;
	if (i == 8)
	{
		if (!c)
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(siginfo->si_pid, SIGUSR1);
		}
		else
			write(STDOUT_FILENO, &c, 1);
		i = 0;
		c = '\0';
	}
}

int	main(void)
{
	int	pid;
	struct sigaction sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	write(STDOUT_FILENO, "This is my server's PID : ", 26);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	while (1)
		pause();
	return (0);
}