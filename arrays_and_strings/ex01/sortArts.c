/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:27:16 by agrodzin          #+#    #+#             */
/*   Updated: 2019/05/14 17:27:17 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     partition(struct s_art **arts, int low, int high){
    struct s_art    *piv = arts[low];
    int             i = low;
    int             j = high;

    while (i < j){
        while (strcmp(arts[i]->name, piv->name) < 0)
            i++;
        while (strcmp(arts[j]->name, piv->name) > 0)
            j--;
        if (i < j){
            struct s_art *tmp = arts[i];
            arts[i] = arts[j];
            arts[j] = tmp;
            if (!strcmp(arts[i]->name, piv->name))
                j--;
        }
    }
    return j;
}

void    quickSort(struct s_art **arts, int low, int high){
    if (low < high){
        int part = partition(arts, low, high);
        quickSort(arts, low, part - 1);
        quickSort(arts, part + 1, high);
    }
}

void    sortArts(struct s_art **arts)
{
    int i = 0;

    while (arts[i])
        i++;
    quickSort(arts, 0, i - 1);
}