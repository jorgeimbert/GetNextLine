/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbert- <jimbert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:24:09 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/24 19:46:43 by jimbert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"   

char	*get_next_line(int fd)
{
	static t_list	*pile = NULL;
	char			*next_line;
	int				char_readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	char_readed = 1;
	next_line = NULL;
	ft_read_and_pile(fd, &pile, &char_readed);
	if (pile == NULL)
		return (NULL);
	ft_extract_line(pile, &next_line);
	if (next_line == NULL)
		return (NULL);
	ft_clean_pile (&pile);
	if (next_line[0] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}

void	ft_read_and_pile(int fd, t_list **pile, int *char_readed_ptr)
{
	char	*buff;

	while (!ft_find_newline(*pile) && *char_readed_ptr != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		*char_readed_ptr = (int)read(fd, buff, BUFFER_SIZE);
		if (*char_readed_ptr == 0 || *char_readed_ptr == -1)
		{
			free(buff);
			return ;
		}
		buff[*char_readed_ptr] = '\0';
		ft_add_to_pile(pile, buff, *char_readed_ptr);
		free(buff);
	}
}

void	ft_add_to_pile(t_list **pile, char *buff, int char_readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (char_readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < char_readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*pile == NULL)
	{
		*pile = new_node;
		return ;
	}
	last = ft_get_last_node(*pile);
	last->next = new_node;
}

void	ft_extract_line(t_list *pile, char **next_line)
{
	int	i;
	int	len;

	if (pile == NULL)
		return ;
	ft_newline(next_line, pile);
	if (*next_line == NULL)
		return ;
	len = 0;
	while (pile)
	{
		i = 0;
		while (pile->content[i])
		{
			if (pile->content[i] == '\n')
			{
				(*next_line)[len++] = pile->content[i];
				break ;
			}
			(*next_line)[len++] = pile->content[i++];
		}
		pile = pile->next;
	}
	(*next_line)[len] = '\0';
}

void	ft_clean_pile(t_list **pile)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		len;

	clean_node = malloc(sizeof(t_list));
	if (pile == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_get_last_node(*pile);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) \
				- i) + 1));
	if (clean_node->content == NULL)
		return ;
	len = 0;
	while (last->content[i])
		clean_node->content[len++] = last->content[i++];
	clean_node->content[len] = '\0';
	ft_free_pile(*pile);
	*pile = clean_node;
}

*/int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("./example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error when open the file");
		return (1);
	}
	printf("\n");
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s", count, next_line);
		free(next_line);
		next_line = NULL;
	}
	close (fd);
	return (0);
}*/
