/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:17:59 by digil-pa          #+#    #+#             */
/*   Updated: 2023/08/16 12:28:33 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	is_onstr(const char *str, int ch)
{
	size_t	i;
	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == ch)
			return (true);
		i += 1;
	}
	return (false);
}

void errors(t_game *game, char *error_msg)
{
	destroy(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
