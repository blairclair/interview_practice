/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:13:13 by agrodzin          #+#    #+#             */
/*   Updated: 2019/05/15 12:13:16 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int getPrice(struct s_art **arts, char *name, int low, int high){
    int middle = (high + low) / 2;
    if (low > high)
        return -1;
    if (!strcmp(arts[low]->name, name))
        return arts[low]->price;
    if (strcmp(arts[low]->name, name) > 0)
        return getPrice(arts, name, 0, middle - 1);
    if (strcmp(arts[low]->name, name) < 0)
        return getPrice(arts, name, middle + 1, high);
    return -1;
}

int searchPrice(struct s_art **arts, int n, char *name){
    return getPrice(arts, name, 0, n);
}