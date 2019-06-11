/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:07:18 by agrodzin          #+#    #+#             */
/*   Updated: 2019/06/11 09:07:22 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank *initTank(void){
	struct s_tank *tank;

	if ((tank = (struct s_tank*)malloc(sizeof(struct s_tank))) == NULL)
		return NULL;
	if ((tank->stacks = (struct s_stack**)malloc(sizeof(struct s_stack*))) == NULL)
		return NULL;
	if ((tank->stacks[0] = (struct s_stack*)malloc(sizeof(struct s_stack))) == NULL)
		return NULL;
	tank->n = 1;
	tank->stacks[0]->sum = 0;
	tank->stacks[0]->elem = NULL;
	return tank;
}

void	addToBeginning(struct s_elem **elem, int energy){
	struct s_elem	*newElem;

	if ((newElem = (struct s_elem*)malloc(sizeof(struct s_elem))) == NULL)
		return ;
	newElem->energy = energy;
	if (!elem || !*elem){
		(*elem) = newElem;
		(*elem)->next = NULL;
		return ;
	}
	newElem->next = (*elem);
	(*elem = newElem);
}

void	tankPush(struct s_tank *tank, int energy){
	if (energy < 10 || energy > 100){
		printf("please enter an energy value of 10 - 100");
			return ;
	}
	if (tank->stacks[tank->n - 1]->sum + energy > 1000){
		return ;
	}
	addToBeginning(&tank->stacks[tank->n - 1]->elem, energy);
	tank->stacks[tank->n - 1]->sum += energy;

}