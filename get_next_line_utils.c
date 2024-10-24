/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbert- <jimbert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:34:04 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/24 18:00:08 by jimbert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_newline(t_list *pile)
{
	int		i;
	t_list	*actual;

	if (pile == NULL)
		return (0);
	actual = pile;
	while (actual)
	{
		i = 0;
		while (actual->content[i])
		{
			if (actual->content[i] == '\n')
				return (1);
			i++;
		}
		actual = actual->next;
	}
	return (0);
}

t_list	*ft_get_last_node(t_list *pile)
{
	t_list	*actual;

	if (pile == NULL)
		return (NULL);
	actual = pile;
	while (actual && actual->next)
		actual = actual->next;
	return (actual);
}

int	ft_newline(char **line, t_list *pile)
{
	int	i;
	int	len;

	len = 0;
	while (pile)
	{
		i = 0;
		while (pile->content[i])
		{
			len++;
			if (pile->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		pile = pile->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return (0);
	(*line)[len] = '\0';
	return (len);
}

void	ft_free_pile(t_list *pile)
{
	t_list	*actual;
	t_list	*next;

	actual = pile;
	while (actual)
	{
		free(actual->content);
		next = actual->next;
		free(actual);
		actual = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
