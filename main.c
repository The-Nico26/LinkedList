#include <stdio.h>
#include <stdlib.h>
#include "Llist.h"

void main(){
	Llist *list = ll_initialisation();

	ll_add(list, 4, 5, 2, 6, 4);

	Llist *list2 = ll_initialisation();

	ll_add(list2, 5, 6, 7, 2, 4, 0);
	ll_setList(list, list2, 2);

	Llist *list3 = ll_initialisation();

	ll_add(list3, 6, 2, 8, 9, 6, 8, 0);
	ll_setList(list3, list, 2);

	ll_toStringDet(list3);

	ll_removeAll(list);
}
