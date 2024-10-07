/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgeimbert <jorgeimbert@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:24:09 by jorgeimbert       #+#    #+#             */
/*   Updated: 2024/10/05 18:21:31 by jorgeimbert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
//#include "get_next_line.h"

int main(void)
{
    int fd;
    char    *next_line;
    int count;

    count = 0;
    fd = open("example.txt", O_RDONLY);
    while (1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break;
        count++;
        printf("[%d]:%s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }
    close(fd);
    return(0);

}