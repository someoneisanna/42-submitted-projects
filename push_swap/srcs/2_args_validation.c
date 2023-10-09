/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_args_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:01:32 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/08 17:06:57 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include "../push_swap.h"

void	ft_args_validation(int ac, char **av);
int		ft_is_num(char *s);
int		ft_is_int(char *s);
int		ft_is_dup(char **args, int i);

/*
	here we check if the args are valid. we will check if:
	1) there are at least 1 arg besides ./push_swap that is being passed
	2) there are no characters that are not numbers
	3) there are no characters that are not integers (and not longs)
	4) there are no duplicates
	note: we can't use atoi - it returns a random int if you pass overflow values
*/

void	ft_args_validation(int ac, char **av)
{
	int		i;

	if (ac < 2)
		ft_perror("Error: wrong number of arguments\n", ac, av);
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		if (ft_is_num(av[i]) == 0)
			ft_perror("Error: arg has a character that isn't a numbr\n", ac, av);
		if (ft_is_int(av[i]) == 0)
			ft_perror("Error: arg has a character that isn't an int\n", ac, av);
		if (ft_is_dup(av, i) == 0)
			ft_perror("Error: arg has one or more duplicates\n", ac, av);
		i++;
	}
}

int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_int(char *s)
{
	int		i;
	int		sig;
	long	res;

	i = 0;
	res = 0;
	sig = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		i++;
	}
	while (ft_isdigit(s[i]) && s[i])
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sig;
	return (res >= INT_MIN && res <= INT_MAX);
}

int	ft_is_dup(char **args, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(args[i]) == ft_atoi(args[j]))
			return (0);
		j++;
	}
	return (1);
}
