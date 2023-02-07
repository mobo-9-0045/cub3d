/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:16:34 by aomman            #+#    #+#             */
/*   Updated: 2023/02/07 18:16:46 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char *color_adjustement(t_var *var)
{
	char *color;

	color = ft_strchr(var->map_elmnt[var->i], ' ');
	color = ft_strrchr(var->map_elmnt[var->i], ' ');
	color = color + 1;
	if (!color)
		return (NULL);
	return (color);
}

static void ft_free (char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	check_floor_color(t_var *var)
{
	int		i;
	char	*color;
	char	**color_elmnt;

	var->f_colors = malloc(sizeof(int) * 3);
	color = color_adjustement(var);
	printf("color :%s<\n", color);
	if (!color || !var->f_colors)
		return (1);
	if (check_spaces(color) == 1)
		return (1);
	color_elmnt = ft_split(color, ',');
	i = 0;
	while (i < 3)
	{
		var->f_colors[i] = ft_atoi(color_elmnt[i]);
		printf("%d\n", var->f_colors[i]);
		i++;
	}
	ft_free(color_elmnt);
	return (0);
}

int	check_sky_color(t_var *var)
{
	int		i;
	char	*color;
	char	**color_elmnt;

	var->c_colors = malloc(sizeof(int) * 3);
	color = ft_strchr(var->map_elmnt[var->i], ' ');
	if (!color)
		return (1);
	color_elmnt = ft_split(color, ',');
	i = 0;
	while (i < 3)
	{
		var->c_colors[i] = ft_atoi(color_elmnt[i]);
		i++;
	}
	ft_free(color_elmnt);
	return (0);
}

int	check_colors(t_var *var)
{
	var->i = 0;
	printf("--------->\n");
	while (var->map_elmnt[var->i])
	{
		if (ft_strstr(var->map_elmnt[var->i], "F ") != NULL)
			if (check_floor_color(var) == 1)
				return (1);
		if (ft_strstr(var->map_elmnt[var->i], "C ") != NULL)
			if (check_sky_color(var) == 1)
				return (1);
		var->i++;
	}
	return (0);
}
