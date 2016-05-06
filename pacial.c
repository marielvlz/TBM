#include "librerias.h"
#include <memory.h>
#include <stdlib.h>

typedef struct tCell {
    int payload;
    struct tCell *next;
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
    while (((root->next)) != NULL){
        root = (Cell*)root->next;
        printf("%d ► ", root->payload);
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
    int cerrar;
    int menu;
    int intervalo;
    printf("\nElige una opcion: \n 0 - Agrega nodo \n 1 - Borra ultimo nodo \n 2 - Imprime Lista \n 3 - Salir \n");
    scanf("%d", &menu);
    return menu;
}

int main(int argc, char* argv[]){
    Cell *root;
    root= (Cell*)malloc(sizeof(Cell));
    root->payload = -1;
    root->next = NULL;
    int menu;
    int menu_final;
    int cont=0;
    int cerrar=1;
    while(cerrar == 1){
        printf("\n Si desea: \n Agregar un nuevo nodo presione 0 \n Borrar el ultimo nodo, presione 1 \n Imprimir la lista de nodos, presione 2 \n Salir del menu, presione 3 \n");
        scanf("%d", &menu);
        if(menu == 0){
            printf("Escribe un numero: ");
            scanf("%d", &menu_final);
            agregar(root, menu_final);
            printf("\n");
            cont=cont+1;
        }
        else if(menu == 1){ //erase
            pop(root);
            cont=cont-1;
        }
        else if(menu == 2){ //imprime_lista
            imprime_lista(root);
        }
        else if(menu == 3){ //salir
            erase(root);
            cerrar=2;
        }
    }
    return 0;
}
