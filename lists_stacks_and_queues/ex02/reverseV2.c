/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:29:03 by agrodzin          #+#    #+#             */
/*   Updated: 2019/06/09 13:29:06 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*pop(struct s_stack *stack){
	struct s_item *tmp;

	if (!stack || !(stack)->item)
		return NULL;
	tmp = stack->item;
	if (!tmp->next){
		free(stack->item);
		stack->item = NULL;
		return tmp;
	}
	stack->item = tmp->next;
	return tmp;
	
}

void	push(struct s_stack *stack, char *word){
	struct s_item *newItem = (struct s_item*)malloc(sizeof(struct s_item));

	newItem->word = word;
	if (!stack || !(stack)->item)
	{
		stack->item = newItem;
		stack->item->next = NULL;
		return;
	}
	newItem->next = stack->item;
	stack->item = newItem;
}

struct s_stack *stackInit(void){
	struct s_stack *newStack = (struct s_stack*)malloc(sizeof(struct s_stack));

	newStack->item = NULL;
	return newStack;
}


void printReverseV2(struct s_node *lst){
	struct s_stack *newStack = stackInit();

	while (lst){
		push(newStack, lst->word);
		lst = lst->next;
	}

	while (newStack->item){
		if (newStack->item->next)
			printf("%s ", newStack->item->word);
		else
			printf("%s\n", newStack->item->word);
		newStack->item = newStack->item->next;
	}		
}
