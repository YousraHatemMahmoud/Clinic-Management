/*Struct for Slots*/

#include <stdio.h>
#include <stdlib.h>
#include "STD_types.h"
#include <string.h>

typedef struct node_type1 node1;

struct node_type1
{
	f32 time;
	node1* tail;
};

node1* head1 = NULL;