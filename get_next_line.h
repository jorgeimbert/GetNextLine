/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbert- <jimbert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:07:57 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/07 15:09:09 by jimbert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 5
#   endif

typedef struct s_list
{
    char            *content;
    struct  s_list  *next;
}           t_list;

char    *get_next_line(int fd);
int     ft_found_newline(t_list *pile);
t_list  *ft_get_last_node(t_list *pile);
void    ft_read_and_pile(int fd, t_list **pile, int *readed_ptr);
void    ft_add_to_pile(t_list **pile, char *buff, int readed);
void    ft_extract_line(t_list *pile, char **line);
void    ft_newline(char **line, t_list *pile);
void    clean_pile(t_list **pile);
int     ft_strlen(const char *str);
void    free_pile(t_list *pile);
#endif