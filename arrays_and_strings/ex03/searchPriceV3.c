/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:47:39 by agrodzin          #+#    #+#             */
/*   Updated: 2019/05/15 14:47:40 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void            add_to_end(struct s_item **item, struct s_art *value, char *key){
    struct s_item		*last = *item;
	struct s_item		*newNode;

	newNode = malloc(sizeof(struct s_item));
	newNode->value = value;
	newNode->key = key;
	newNode->next = NULL;
	if (item == NULL || *item == NULL){
		(*item) = newNode;
		return ;
	}
	last = (*item);
	while (last->next != NULL){
		last = last->next;
	}
	last->next = newNode;
	return ;	
}

size_t             hash(char *key){
    long hashVal = 0;
	while (*key) {
		hashVal = (hashVal << 4) + *(key++);
		long g = hashVal & 0xF0000000L;
		if (g != 0) hashVal ^= g >> 24;
		hashVal &= ~g;
	}
	return hashVal % 5;	
}

struct s_dict   *dictInit(int capacity){
    struct s_dict   *newDict;
	newDict = malloc(sizeof(struct s_item*) * capacity);
    if ((newDict->items = malloc(capacity)) == NULL)
        return NULL;
     return newDict;
}

int             dictInsert(struct s_dict *dict, char *key, struct s_art *value){
    int hashedValue = hash(key);

	add_to_end(&dict->items[hashedValue], value, key);    
	return 1;
}

struct s_art *dictSearch(struct s_dict *dict, char *key){
    int hashedValue = hash(key);
    struct s_item    *head;

    if (!strcmp(dict->items[hashedValue]->value->name, key))
        return dict->items[hashedValue]->value;
    head = dict->items[hashedValue];
    while (head->next != NULL){
        if (!strcmp(head->value->name, key)){
            return head->value;
        }
        head = head->next;
    }
	return NULL;
}

int searchPrice(struct s_dict *dict, char *name){
	struct s_art *ans = dictSearch(dict, name);

	if (ans == NULL){
		return -1;
	}
	return ans->price;
}

