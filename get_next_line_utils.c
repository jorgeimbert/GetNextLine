/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbert- <jimbert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:34:04 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/07 15:09:09 by jimbert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Buscamos un nuevo cartacter en la lista del contenedor PILE.
int ft_found_newline(t_list *pile)
{
    int     i;
    t_list  *actual;
    
    if (pile == NULL)
        return(0);
    actual = ft_get_last_node(pile);
    i = 0;
    while (actual->content[i])
    {
        if (actual->content[i] == '\n')
            return(1);
        i++;
    }
    return(0);
}

// Retornamos un puntero al último nodo de nuestro contenedor de almacenado.
t_list  *ft_get_last_node(t_list *pile)
{
    t_list  *actual;

    actual = pile;
    while (actual && actual->next)
        actual = actual->next;
    return(actual);
}

// Calculamos n char en linea ACTUAL y \n, ->en la memoria.
void    ft_newline(char **line, t_list *pile)
{
    int i;
    int len;
    
    len = 0;
   while (pile)
   {
        i = 0;
        while (pile->content[i])
        {
            if (pile = pile->content[i] = '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        pile = pile->next;
    } 
    *line = malloc(sizeof(char) * (len + 1));
}

// Liberamos el contenedor STASH.
void    free_pile(t_list *pile)
{
    t_list *actual;
    t_list *next;
 
    actual = pile;
    while (actual)
    {
        free(actual->content);
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