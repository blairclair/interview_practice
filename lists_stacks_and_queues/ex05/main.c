#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	tankPush(tank, 50);
	for (int i = 0; i < tank->n; i++){
		while (tank->stacks[i]->elem){
			printf("stack number %d energy: %d\n", i + 1, tank->stacks[i]->elem->energy);
			tank->stacks[i]->elem = tank->stacks[i]->elem->next;
		}
	}
	return (0);
}



// Function used for the test
// Don't go further :)
