/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbert- <jimbert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:24:09 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/07 15:09:09 by jimbert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"   

char *get_next_line(int fd)
{
    static  t_list *pile = NULL;
    char    *next_line;
    int     readed;

// 1. Verificamos q el fichero existe, que BUFFER 0 o (-), o q esta vacio.
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, *next_line, 0) < 0)
        return (NULL);
    readed = 1;
    next_line = NULL;

//2. Leemos de FD y añadimos a la lista
    ft_read_and_pile(fd, &pile, &readed);
    if (pile == NULL)
        return (NULL);
    
//3. Extraemos la LINEA del contenedor PILE
    ft_extract_line(pile, &next_line);

//4. Limpiamos el contenedor PILE
    ft_clean_pile (&pile);
    if (next_line[0]) == '\0')
    {
        free_pile(pile);
        pile = NULL;
        free)line);
        return (NULL);
    }
        return(next_line);
}

// Leemos con READ() los caracteres y acumulamos en el PILE
void    ft_read_and_pile(int fd, t_list **pile, int *readed_ptr)
{
    char    *buff;
    
    while (!found_newline(*pile) && *readed_ptr != 0)
    {
        buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (buff = NULL) 
            return;
    
        *readed_ptr = (int)read(fd, buff, BUFFER_SIZE);
        if ((*pile == NULL && *readed_ptr == 0) || *readed_ptr == -1)
        {
            free(buff);
            return;
        }
        buff[*readed_ptr] = '\0';
        ft_add_to_pile(pile, buff, *readed_ptr);
        free(buff);
    }

}

/* Añadimos el contenido del BUFFER al final del PILE*/
void    ft_add_to_pile(t_list **pile, char *buff, int readed)
{
    int i;
    t_list  *actual;
    t_list  *new_node;
    
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL);
        return;
    new_node->next = NULL;
    new_node->content = malloc(sizeof(char) * (readed + 1));
    if (new_node->content == NULL)
        return;
    i = 0;
    while (buff[i] && i < readed)
    {
        new_node->content[i] = buff[i];
        i++;
    }
    new_node->content[i] = '\0';
    if (*pile == NULL)
    {
        *pile = new_node;    
        return;
    }
    last = ft_get_last_node(*pile);
    last->next = new_node;
}

/* Extraemos todos los chars de la PILA y las ubicamos en la LINEA, stop after 1 \n*/
void    ft_extract_line(t_list *pile, char **line)
{
    int i;
    int len;
    
    if (pile == NULL)
        return;
    ft_newline(line, pile);
    if (*line == NULL)
        return;
    len = 0;
    while (pile)
    {
        i = 0;
        while (pile->content[i]
        {
            if (pile->content[i] == '\n'
            {
                (*line)[len++] = pile->content[i];
                break;
            })
            (*line)[len++] = pile->content[i++];
        }
        pile = pile->next;
    }
    (*line)[i] = '\0';
}


/* after extracting Line, Clear Stash, but keep what was readed behind /n*/
void    clean_pile(t_list **pile)
{
    t_list  *last;
    t_list  *clean_node;
    int     i;
    int     len;

    clean_node = malloc(sizeof(t_list));
    if (pile == NULL || clean_node == NULL)
        return;
    clean_node->next = NULL;
    last = ft_get_last_node(*pile);
    i = 0;
    while (last->content[i] && last->content[i] != 'ºn')
        i++;
    if (last->content && last->content[i] == '\n')
        i++;
    clean_node->content = malloc(sizeof(char) *((ft_strlen(last->content) - i) + 1));
    if (clean_node->content == NULL)
        return;
    len = 0;
    while(last->content[i])
        clean_node->content[len++] = last->content[i++];
    clean_node->content[len] = '\0';
    free_pile(*pile);
    *pile = clean_node;
}