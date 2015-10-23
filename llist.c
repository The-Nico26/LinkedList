#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include "llist.h"

struct Element{
	TYPE_VARIABLE valeur;
	struct Element *nxt;
	struct Element *pre;
};
struct Llist{
	int size;
	Element *first;
};
Llist *ll_initialisation(){
	Llist *list = malloc(sizeof(Llist));

	ll_secuList(list);
	list->first = NULL;

	return list;
}
Llist *ll_initialisationNbr(int nbr, TYPE_VARIABLE valeur){
	Llist *list = malloc(sizeof(Llist));

	ll_secuList(list);
	list->first = NULL;

	for(int a = 0; a < nbr; a++){
		ll_addStart(list, valeur);
	}
	return list;
}
void ll_addStart(Llist *list, TYPE_VARIABLE variable ){
	ll_secuList(list);

	Element *new = malloc(sizeof(Element));
	ll_secuElement(new);

	new->valeur = variable;
	new->nxt = list->first;
	new->pre = NULL;
	list->first = new;
}
void ll_addElement(Llist *list, TYPE_VARIABLE val, int pos){
	ll_secuList(list);
	if(pos > ll_size(list)){
		return;
	}

	Element *add = malloc(sizeof(Element));
	ll_secuElement(add);

	add->valeur = val;
	Element *res = list->first;

	pos--;
	for(int a = 0; a < pos && res != NULL; a++){
		res = res->nxt;
	}
	add->nxt = res->nxt;
	res->nxt = add;
}
void ll_add(Llist *list, int nbr, ...){
	ll_secuList(list);
	
	va_list ad;
	va_start(ad, nbr);

	if(list->first == NULL){
		ll_addStart(list, va_arg(ad, TYPE_VARIABLE));
		nbr--;
	}

	Element *temp = list->first;
	
	while(temp->nxt != NULL){
		temp = temp->nxt;
	}

	
	
	for(int a = 0; a <= nbr && temp != NULL; a++){
		
		Element *element = malloc(sizeof(*element));
		ll_secuElement(element);

		TYPE_VARIABLE vale = va_arg(ad, TYPE_VARIABLE);

		element->valeur = vale;
		element->nxt = temp;
		if(a == nbr)
			temp->nxt = NULL;
		else
			temp->nxt = element;
		temp = temp->nxt;
	}

	va_end(ad);
}
void ll_removValeur(Llist *list, TYPE_VARIABLE val){
	ll_secuList(list);
	Element *res = list->first;
	int pos = ll_indexOf(list, val);

	if(pos == 0){
		Element *remov = list->first;
		list->first = list->first->nxt;
		free(remov);
		return;
	}

	Element *back = ll_containt(list, pos-1);
	if(pos == ll_size(list)){
		back->nxt = NULL;
		Element *remov = ll_containt(list, pos);
		free(remov);
		return;
	}
	else{
		Element *remov = ll_containt(list, pos);
		back->nxt = remov->nxt;
		free(remov);
		return;
	}
}
void ll_removIndex(Llist *list, int pos){
	ll_secuList(list);
	Element *element = ll_containt(list, pos);

	ll_removValeur(list, element->valeur);
}
void ll_removeAll(Llist *list){
	ll_secuList(list);

	while(list->first != NULL){
		Element *remov = list->first;
		list->first = remov->nxt;
		free(remov);
	}

	free(list);
}
int ll_indexOf(Llist *list, TYPE_VARIABLE val){
	ll_secuList(list);

	Element *element = list->first;
	int i = 0;

	while(element != NULL){
		if(element->valeur == val){
			return i;
		}
		i++;
		element = element->nxt;
	}
	return -1;
}
Element *ll_containt(Llist *list, int pos){
	ll_secuList(list);

	Element *element = list->first;
	for(int a = 0; a < pos && element != NULL; a++){
		element = element->nxt;
	}

	return element;
}
int ll_size(Llist *list){
	if(list == NULL)
		return 0;
	
	int i = 0;
	Element *element = list->first;
	while(element != NULL){
		element = element->nxt;
		i++;
	}

	return i;
}
void ll_toString(Llist *list){
	ll_secuList(list);

	Element *element = list->first;

	while(element != NULL){
		printf("%d | ", element->valeur);
		element = element->nxt;
	}

	printf("\n");
}
void ll_toStringDet(Llist *list){
	ll_secuList(list);

	Element *element = list->first;
	printf("Il y a %d d'element\nMemoire de la liste : %d\n", list->size, list);

	while(element != NULL){
		printf("-{Valeur : %d, Avant : %d, Apres : %d}-",element->valeur, element->pre, element->nxt);
		element->element->nxt;
	}
	printf("\n");
}
void ll_secuList(Llist *list){
	if(list == NULL){
		printf("La liste est vide\n");
		exit(EXIT_FAILURE);
	}
}
void ll_secuElement(Element *element){
	if(element == NULL){
		printf("L'element est vide\n");
		exit(EXIT_FAILURE);
	}
}
int ll_isEmpty(Llist *list){

	return (list == NULL)? 1 : 0;
}
Llist *ll_clone(Llist *list, ...){
	ll_secuList(list);

	Llist *copy = ll_initialisation();

	ll_secuList(copy);
	
	va_list ap;
	va_start(ap, list);
		int start = va_arg(ap, int);
		int end = va_arg(ap, int);
		if(end == 0 || end > ll_size(list))
			end = ll_size(list);
	va_end(ap);

	Element *res = ll_containt(list, start);
	ll_addStart(copy, res->valeur);
	start++;
	for(int a = start; a < end && res != NULL; a++){
		res = res->nxt;
		ll_add(copy, 1, res->valeur);
	}
	return copy;
}
void ll_fill(Llist *list, TYPE_VARIABLE val){
	ll_secuList(list);

	Element *res = list->first;
	res->valeur = val;
	while(res->nxt != NULL){
		res = res->nxt;
		res->valeur = val;
	}
}
Llist *ll_reverse(Llist *list){
	ll_secuList(list);

	Llist *save = ll_initialisation();

	Element *res = list -> first;

	while(res != NULL){
		ll_addStart(save, res->valeur);
		res = res->nxt;
	}
	ll_removeAll(list);
	return save;
}
void ll_addList(Llist *list, Llist *list2){
	ll_secuList(list); 
	ll_secuList(list2);
	int lastIndex = ll_size(list);

	Element *last = ll_containt(list, lastIndex);
	last->nxt = list2->first;

	free(list2);
}
void ll_tri(Llist *list){
	ll_secuList(list);

	int flag = 1;
	int i = 0;
	while(flag){
		flag = 0;
		i = 0;
		int size = ll_size(list);
		while (i <  size - 1){
			Element *element1 = ll_containt(list, i);
			Element *element2 = ll_containt(list, i + 1);

			if(element1->valeur > element2->valeur){

				TYPE_VARIABLE c = element1->valeur;
				element1->valeur = element2->valeur;
				element2->valeur = c;
				flag = 1;
			}
			i++;
		}
	}
}
void ll_setElement(Llist *list, TYPE_VARIABLE valeur, int pos){
	ll_secuList(list);
	Element *element = ll_containt(list, pos);
	element->valeur = valeur;
}
TYPE_VARIABLE ll_getValeur(Llist *list, int pos){
	ll_secuList(list);
	return ll_containt(list,pos)->valeur;
}
Llist *ll_transTab(TYPE_VARIABLE valeur[], int nbr){
	Llist *list = ll_initialisation();
	ll_secuList(list);
	nbr--;
	for(int a = nbr; a >= 0; a--){
		ll_addStart(list, valeur[a]);
	}

	return list;
}