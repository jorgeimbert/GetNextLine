/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgeimbert <jorgeimbert@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:07:57 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/05 15:30:29 by jorgeimbert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 5
#   endif

typedef struct s_list
{
    char            *content;
    struct  s_list  *next;

}       t_list;

char    *get_next_line(int fd);
char    *ft_read_and_stash(int fd, t_list **stash, int *readed_ptr;
char    *ft_add_to_stash(t_list **stash, char *buff, int readed);
char    *ft_extract_line(t_list *stash, char *next_line);

