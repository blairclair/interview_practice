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
    int             j = low - 1;

    for (int i = low; i < high; i++){
        if (strcmp(arts[i]->name, piv->name) <= 0){
            j++;
            struct s_art    *tmp = arts[i];
            arts[i] = arts[j];
            arts[j] = tmp;        
        }
    }
    return j + 1;
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
    quickSort(arts, 0, i);
}