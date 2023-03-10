/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:23:22 by aomman            #+#    #+#             */
/*   Updated: 2023/02/08 19:23:35 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_key_c(t_var *var)
{
	int	strlen_var;
	int	i;

	strlen_var = ft_strlen(var->map_elmnt[var->i]);
	i = 0;
	while (i < strlen_var)
	{
		if (var->map_elmnt[var->i][i] == 'C')
			break ;
		if (var->map_elmnt[var->i][i] > 33)
			return (1);
		i++;
	}
	return (0);
}

char	*remove_spaces_in_end(char *str)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			j++;
		i++;
	}
	color = ft_substr(str, 0, ft_strlen(str) - j);
	return (color);
}

char	*remove_spaces_in_begin(char *str)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		else
			break ;
		i++;
	}
	color = ft_substr(str, j, ft_strlen(str));
	return (color);
}

int	ft_arealpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			i++;
		if (str[i] > 57 || str[i] < 48)
			return (1);
		i++;
	}
	return (0);
}

char	*color_adjustement(t_var *var)
{
	char	*color;

	color = ft_strchr(var->map_elmnt[var->i], ' ');
	if (!color)
		return (NULL);
	color = remove_spaces_in_begin(color);
	if (!color)
		return (NULL);
	color = remove_spaces_in_end(color);
	if (!color)
		return (NULL);
	if (ft_arealpha(color) == 1)
		return (NULL);
	if (ft_strcmp(color, "") == 0)
		return (NULL);
	return (color);
}
