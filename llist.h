typedef struct Element Element;
typedef struct Llist Llist;
#define TYPE_VARIABLE int

void ll_addStart(Llist *list, TYPE_VARIABLE variable); //Rajoute une valeur au début de la liste
void ll_addElement(Llist *list, TYPE_VARIABLE valeur, int pos); //Rajoute une valeur à une position
void ll_add(Llist *list, int nbr, ...); //Rajoute plusieurs valeurs à la fin de la liste
void ll_addList(Llist *list, Llist *list2); //Rassemble 2 listes en 1 seule
void ll_addEnd(Llist *list, TYPE_VARIABLE valeur); //Rajoute une valeur à la fin de la liste;
Element *ll_containt(Llist *list, int pos); //Renvoie une valeur selon la position
Llist *ll_clone(Llist *list, ...); //Copi un fragment d'une liste dans une nouvelle liste. Optionnel : {int start, int end};
void ll_fill(Llist *list, TYPE_VARIABLE valeur); //Remplit tout la liste d'une seul valeur
TYPE_VARIABLE ll_getValeur(Llist *list, int pos); //Récupére la valeur d'un élément à la position voulue
Llist *ll_getLlist(Llist *list, int dimension, ...);//Renvoie une liste qui se trouve dans un élément.
int ll_indexOf(Llist *list, TYPE_VARIABLE valeur); //Cherche une valeur dans la list et retour son index
Llist *ll_initialisation(); //Initialise la liste avec aucun élément.
Llist *ll_initialisationNbr(int nbr, TYPE_VARIABLE valeur); //Initialise la liste avec un nombre d'élément nbr et une valeur défini.
int ll_isEmpty(Llist *list); //Renvoi 1 si la list est null
void ll_removValeur(Llist *list, TYPE_VARIABLE valeur); //Supprime une valeur dans le tableau
void ll_removIndex(Llist *list, int pos); //Supprime une valeur à un position précise
void ll_removeAll(Llist *list); //Supprime tout la liste
Llist *ll_reverse(Llist *list); //Renverse la liste
int ll_size(Llist *list); //Renvoi la taille de la liste
void ll_secuList(Llist *list); //Exit si la list est null
void ll_secuElement(Element *element); //Exit si l'élément est null
void ll_setElement(Llist *list, TYPE_VARIABLE valeur, int pos); //Modifier une valeur à la position voulue
void ll_setList(Llist *list, Llist *list2, int pos);
void ll_toString(Llist *list); //Ecrit la liste
void ll_toStringDet(Llist *list); //Ecrit la liste en détaille
Llist *ll_transTab(TYPE_VARIABLE valeur[], int nbr); //Transforme un tableau en liste
void ll_tri(Llist *list); //Tri les valeurs d'une liste
