#include <stdio.h>
#include <stdlib.h>
#include "Llist.h"

void main(){
	Llist *list = ll_initialisation();

	ll_add(list, 4, 5, 2, 6, 4);

	Llist *list2 = ll_initialisation();

	ll_add(list2, 5, 6, 7, 2, 4, 0);
	ll_setList(list, list2, 2);
	ll_toStringDet(list);



	ll_removeAll(list);
}
