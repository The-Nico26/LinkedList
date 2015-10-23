#include <stdio.h>
#include <stdlib.h>
#include "Llist.h"

void main(){
	Llist *list = ll_initialisation();

	ll_add(list, 4, 5, 2, 6, 4);
	ll_toString(list);

	ll_setElement(list, +2, 1);
	ll_toString(list);

	printf("Indice : %d\n", ll_indexOf(list, 5));
	ll_addElement(list, 7, 2);

	printf("Valeur : %d\n", ll_getValeur(list, 0)+1);
	ll_toString(list);

	ll_tri(list);
	ll_toString(list);

	int tab[9] = {1,2,3,4,5,6,7,8,9};
	Llist *list2 = ll_transTab(tab, 9);
	ll_toString(list2);
	ll_removeAll(list);
	ll_removeAll(list2);

	Llist *liste = ll_initialisation();
	

}