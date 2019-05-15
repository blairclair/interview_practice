/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:20:02 by agrodzin          #+#    #+#             */
/*   Updated: 2019/05/14 17:20:09 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_art **arts, char *name){
    int i = 0;

    while (arts[i]){
        if (!strcmp(arts[i]->name, name))
            return arts[i]->price;
        i++;
    }
    return -1;
}