#include <stdio.h>
#include <stdlib.h>
#include "Llist.h"

void main(){
	Llist *list = ll_initialisation();

	ll_add(list, 4, 5, 2, 6, 4);
	ll_toString(list);
	ll_addElement(list, 10, 3);
	ll_toStringDet(list);


}