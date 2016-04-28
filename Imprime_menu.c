#include "librerias.h"
#include <memory.h>
#include <stdlib.h>
typedef struct tCell {

	int payload;
	void* next;
} Cell;

Cell* agregar(Cell *root, int numero){ //Agrega nodo
	Cell *nuevo_nodo;
	nuevo_nodo = (Cell*)malloc(sizeof(Cell));
	nuevo_nodo -> payload= numero;
	nuevo_nodo->next = NULL;
	Cell *cursor = root;
	while(cursor->next!= NULL){
		cursor = (Cell *)cursor -> next;
		}
	cursor -> next = (void*)nuevo_nodo;
	return root;
	}

void imprime_lista(Cell *root){ //Imprime Lista
	while ((root = (root->next)) != NULL){
		printf("--> %d", root->payload);
		root = root->next;
		}
}

Cell *pop(Cell *root){ //Salir
	Cell *cursor = root;
 	if(root->next == NULL) return root;
 	while(((Cell*)cursor->next)->next != NULL){
 		cursor = (Cell*)cursor->next;
 	}
 	free(cursor->next);
 	cursor->next = NULL;
 	return root;
}	
	
Cell *erase(Cell *root){ //Borrar
	while (root->next != NULL){
		pop(root);
	}
return root;
}

int imprime_menu(){ 
	int menu;
	printf("Elige una opcion: \n 0 - Agrega nodo \n 1 - Borra ultimo nodo \n 2 - Imprime Lista \n 3 - Salir");
	scanf("%d", &menu);
	return menu;
}
	
int main(int argc, char* argv[]){
 	Cell root;
 	int menu_final;
 	root.payload = -1;
 	root.next = NULL;
	int menu = imprime_menu();
 	while(menu != 3){
 		if(menu == 0){
 			printf("Escribe un numero (ya sea 0, 1, 2 ó 3): ");
 			scanf("%d", &menu_final);
 			agregar(&root, menu_final);
 			printf("\n");
 		}
 		else if(menu == 1){
 			pop(&root);
 		}
 		else if(menu == 2){
 			imprime_lista(&root);
 		}
 		printf("\n");
 		menu = imprime_menu();
 		}
 	erase(&root);
 	return 0;
}
