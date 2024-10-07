/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgeimbert <jorgeimbert@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:34:04 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/05 19:58:54 by jorgeimbert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// Buscamos un nuevo cartacter en la lista del contenedor STASH.
int ft_found_newline(t_list *stash)
{
    int     i;
    t_list  *actual;
    
    if (stash == NULL)
        return(0);
    actual = ft_lst_line(stash);
    i = 0;
    while (actual->content[i])
    {
        if (actual->content[i] = '\n')
            return(1);
        i++;
    }
    return(0);
}

// Retornamos un puntero al último nodo de nuestro contenedor de almacenado.
t_list  *ft_lst_get_last(t_list *stash)
{
    t_list  *actual;

    actual = stash;
    while (actual && actual->next)
        actual = actual->next;
    return(actual);
}

// Calculamos n char en linea ACTUAL y \n, ->en la memoria.
void    ft_create_line(char **line, t_list *stash)
{
    int i;
    int len;
    
    len = 0;
   while (stash)
   {
        while (stash->content[i])
        {
            if (stash = stash->content[i] = '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        stash = stash->next;
    } 
    *line = malloc(sizeof(char) * (len + 1));
}

// Liberamos el contenedor STASH.
void    free_stash()
{
    t_list *actual;
    t_list *next;
 
    actual = stash;
    while (stash)
    {
        free(actual_content);
        next = actual->next;
        free(actual);
        actual = next;
    }   
}

//
int ft_strlen(const char *str)
{
    int len;
    
    len = 0;
    while (*(str++)
        len++;
    return(len);
}