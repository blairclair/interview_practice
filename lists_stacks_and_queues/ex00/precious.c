/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:20:37 by agrodzin          #+#    #+#             */
/*   Updated: 2019/06/07 14:20:44 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
typedef struct s_node t_node;

void	add_to_end(t_node **code, char c){
	t_node	*head;
	t_node	*newNode = (t_node*)malloc(sizeof(t_node));
	
	newNode->c = c;
	newNode->next = NULL;
	if (!code || !(*code)){
		(*code) = newNode;
	}
	else{
		head = (*code);
		while (head->next){
			head = head->next;
		}
		(head)->next = newNode;
		newNode->prev = head;
	}
}

void	delFromBegining(t_node **code){
	t_node	*head;

	if (!code || !(*code))
		return ;
	head = (*code)->next;
	(*code) = head;
	
}

void	delFromEnd(t_node **code){
	t_node	*head;

	if (!code || !(*code))
		return ;
	head = (*code);
	while (head->next->next){
		(head) = (head)->next;
	}
	(head)->next = NULL;
	free(head->next);
}

void	addToBeginning(t_node **code, char c){
	t_node	*newNode = (t_node*)malloc(sizeof(t_node));

	newNode->c = c;
	if (!code || !*(code)){
		(*code) = newNode;
		(*code)->next = NULL;
	}
	else{
		(*code)->prev = newNode;
		newNode->next = (*code);
		(*code) = newNode;
	}
}

void	FrontToBack(t_node **code){
	char tmp = (*code)->c;
	delFromBegining(code);
	add_to_end(code, tmp);
}

void	BackToFront(t_node **code){
	t_node	*head;
	char	tmp;

	if (!code || !(*code))
		return ;
	head = (*code);
	while (head->next)
		head = head->next;
	tmp = head->c;
	delFromEnd(code);
	addToBeginning(code, tmp);
}

char	*precious(int *text, int size){
	t_node	*code;
	int	len = strlen(CS);
	char	*buf = (char*)malloc((sizeof(char) * size) + 1);
	int		bufLen = 0;

	for (int i = 0; i < len; i++){
		add_to_end(&code, CS[i]);
	}
	for (int j = 0; j < size; j++){
		if (text[j] < 0){
			text[j] *= -1;
			for (int k = 0; k < text[j]; k++){
				BackToFront(&code);
			}
		}
		else{
			for (int k = 0; k < text[j]; k++){
				FrontToBack(&code);
			}
		}
		buf[bufLen] = code->c;
		bufLen++;
	}
	return buf;//tmp
}