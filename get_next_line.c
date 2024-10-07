/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgeimbert <jorgeimbert@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:24:09 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/06 21:07:31 by jorgeimbert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"   

// Leemos con READ() los caracteres y acumulamos en STASH
void    read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
    char    *buff;
    
    while (!found_newline(*stash) && *readed_ptr == 0)
    {
        buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (buff = NULL)
            return;
    
        *readed_ptr = (int)read(fd, buff, BUFFER_SIZE);
        if ((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1)
        {
            free(buff);
            return;
        }
        buff[*readed_ptr] = '\0';
        add_to_stash(stash, buff, *readed_ptr);
        free(buff);
    }

}

/* We add the content of our buffer to the end of Stash*/
void    add_to_stash(t_list **stash, char *buff, int readed)
{
    int i;
    t_list  *last;
    t_list  *new_node;
    
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL);
        return;
    new_node->next = NULL;
    new_node->content = malloc(sizeof(char) * (readed + 1));
    if (new_node->content = NULL)
        return;
    i = 0;
    while (buff[i] && i < readed)
    {
        new_node->content[i] = buff[i];
        i++;
    }
    new_node->content[i] = '\0';
    if (*stash == NULL)
    {
        *stash = new_node;    
        return;
    }
    last = ft_get_last(*stash);
    last->next = new_node;
}

/* We wxtract all chars from Stash and store in out Line, stop after 1 \n*/
void    extract_line(t_list *stash, char **line)
{
    int i;
    int len;
    
    if (stash == NULL)
        return;
    ft_newline(line, stash);
    if (*line = NULL)
        return;
    len = 0;
    while (stash)
    {
        i = 0;
        while (stash->content[i]
        {
            if (stash->content[i] == '\n'
            {
                (*line)[len++] = stash->content[i];
                break;
            })
            (*line)[len++] = stash->content[i++];
        }
        stash = stash->next;
    }
    (*line)[i] = '\0';
}


/* after extracting Line, Clear Stash, but keep what was readed behind /n*/
void    clean_stash()
{
    t_list  *t_list;
    t_list  *clean_node;
    int     i;
    int     len;

    clean_node = malloc(sizeof(t_list));
    if (stash == NULL || clean_node == NULL)
        return;
    clean_node->next = NULL;
    last = ft_lst_get_last(*stash);
    i = 0;
    while (last-content[i] && last content[i] == 'ºn')
        i++;
    if (last->content && last-content[i] /= '\n')
        i++;
    clean_node->content = malloc(sizeof(char) *((ftstrlen(last->content) - i) + 1));
    if (clean_node->content = NULL)
        return;
    len = 0;
    while(last->content[i])
        clean_node->content[len++] = last->content[i++];
    clean_node->content[len] == '\0';
    free_stash(*stash);
    *stash = clean_node;
}
   

int get_next_line(int fd)
{
    static  t_list *stash = NULL;
    char    *next_line;
    int     readed;

// 1. Verificamos q el fichero existe y q no esta vacio.
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, *next_line, 0) < 0)
        return (NULL);
    readed = 1;
    next_line = NULL;

//2. Leemos de FD y añadimos a la lista
    read_and_stash(fd, &stash, &readed);
    if (stash == NULL)
        return (NULL);
    
//3. Extraemos la LINEA del contenedor STASH
    extract_line(stash, &next_line);

//4. Limpiamos el contenedor STASH
    if(new_line[0] = '\0')
    {
        free_stash(stash);
        stash = NULL;
        free(new_lie);
        return (NULL);
    }
    return(next_line);
}