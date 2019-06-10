/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:15:37 by agrodzin          #+#    #+#             */
/*   Updated: 2019/06/09 18:15:39 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	pop(struct s_stack *stack){
	struct s_item *tmp;

	if (!stack || !(stack)->item)
		return 0;
	tmp = stack->item;
	if (!tmp->next){
		free(stack->item);
		stack->item = NULL;
		return stack->item->idx;
	}
	stack->item = tmp->next;
	return stack->item->idx;
}

void push(struct s_stack *stack, int idx){
	
	struct s_item *newItem = (struct s_item*)malloc(sizeof(struct s_item));

	newItem->idx = idx;
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

 char *console(void){
	 
	int		idx = 0;
 	char	*buf = (char*)malloc(sizeof(char) * 260);
	char	*ans = (char*)malloc((sizeof(char) * 255) + 1);
	struct	s_stack *newStack = stackInit();
	int		len;
	size_t	buf_size = 255;

	while (1){
		printf("?: ");
		bzero(buf, strlen(buf));
		getline(&buf, &buf_size, stdin);
		len = strlen(buf);
		buf[len - 1] = '\0';
		if (!strcmp(buf, "UNDO")){
			ans[newStack->item->idx] = '\0';
			ans[newStack->item->idx + 1] = '\0';
			printf("%s\n", ans);
			idx = newStack->item->idx;
		}
		else if (!strcmp(buf, "SEND")){
			printf("%s\n", ans);
			return ans;
		}
		else{
			push(newStack, idx);
			if (idx != 0){
				memmove(ans + idx, " ", 1);
				memmove(ans + idx + 1, buf, len);
				ans[idx + 1 + len] = '\0';
				idx += len;
			}
			else
			{
				strcpy(ans, buf);
				idx += len - 1;
			}	
			printf("%s\n", ans);
		}
	}	
 }