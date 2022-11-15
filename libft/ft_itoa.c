/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:57:32 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/05 17:26:09 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_array_size(int n)
{
	int		count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		mod;
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = n;
	sign = (num < 0);
	num = num < 0 ? num * -1 : num;
	str = (char *)malloc(sizeof(char) * (ft_array_size(n) + sign + 1));
	if (!str)
		return (NULL);
	if (!num)
		str[i++] = 0 + '0';
	while (num)
	{
		mod = num % 10;
		num = num / 10;
		str[i++] = mod + '0';
	}
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
