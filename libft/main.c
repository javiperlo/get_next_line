/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:25:56 by javperez          #+#    #+#             */
/*   Updated: 2023/09/18 17:42:30 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	*prueba;
	int		res;

	prueba = "Hola que tal";
	res = ft_strlen(prueba);
	printf ("La funcion ft_strlen: %d", res);
}
