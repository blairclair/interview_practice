/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:49:26 by agrodzin          #+#    #+#             */
/*   Updated: 2019/06/07 17:49:28 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	recurseReverse(struct s_node *lst)
{
	if ((lst)->next)
	{
		recurseReverse((lst)->next);
		printf(" ");
	}
	printf("%s", (lst)->word);
}

void	printReverse(struct s_node *lst)
{
	recurseReverse(lst);
	printf("\n");
}
