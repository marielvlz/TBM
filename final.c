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

void buscar_nodo(Cell *root, int x, int y){ //Buscar
    Cell *cursor= NULL;
    if (x > y or y <= 0){
        printf("ERROR\n Favor de seleccionar uno de los numeros que se encuentran en el menu.\n");
    } 
            if (x<=y){
                cursor=root;
                for (int i = 0; i < x; ++i){
                    if (cursor->next){
                        cursor=cursor->next;
                    }
                }
                printf("Resultado de busqueda: el nodo numero %d tiene valor de %d \n",x, cursor->payload);
            }
}

Cell *erase_nodo(Cell *root, int x, int y){
    Cell *cursor= NULL;
    if (x>y or x<=0){
           printf("ERROR\n Favor de seleccionar uno de los numeros que se encuentran en el menu.\n");
    } 
    else{
        cursor=root;
        for (int i = 1; i < x; ++i){
            if (cursor->next){
                cursor=cursor->next;
            }
        }
        Cell *z=((Cell*)cursor->next)->next;
        free((void*)cursor->next);
        cursor->next=z;  
    }
return root;  
}

Cell *modificar(Cell *root, int x, int y, int w){
    Cell *cursor=NULL;
    if (x>y or x<=0){
        printf("ERROR\n Favor de seleccionar uno de los numeros que se encuentran en el menu.\n");
    }
    else {
        cursor=root;
        for(int i=0; i<x; i++){
            if (cursor->next!=NULL)
                cursor=cursor->next;
            }
            cursor->payload=w;
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
    int indice;
    int menu_final;
    int cont=0;
    int cerrar=1;
    while(cerrar == 1){
        printf("\n Si desea: \n Agregar un nuevo nodo, presione 0 \n Borrar el ultimo nodo, presione 1 \n Imprimir la lista de nodos, presione 2 \n Buscar un nodo, presione 3 \n Eliminar un nodo especifico, presione 4 \n Modificar un nodo especifico, presione 5 \n Salir del menu, presione 6 \n");
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
        else if(menu == 3){ //buscar_nodo
            int indice;  
            printf("Por favor, seleccione cual es el nodo que desea buscar.\n");
            scanf("%d", &indice);
            buscar_nodo(root, indice, cont);
        }
        else if (menu == 4){ //erase_nodo
            int indice;
            printf("Favor de seleccionar el nodo que desea eliminar\n");
            scanf("%d", &indice); 
            erase_nodo(root, indice, cont);
            cont=cont-1; 
        }
        else if(menu == 6){ //pop
            erase(root);
            cerrar=2;
        }
        else if (menu == 5){ //modificar
            int indice;
            int u;
            printf("Por favor, elija el nodo que guste modificar \n");
            scanf("%d", &indice);
            buscar_nodo(root, indice, cont);
            printf("Favor de escribir el numero que desee sustituir el valor anterior\n");
            scanf("%d", &u);
            modificar(root, indice, cont, u);
            printf("Afortunadamente, el nodo ha sido modificado.\n");
        } 
        else{
            printf("Error, favor de insertar un valor que este en el menu \n");
        }
    }
    return 0;
}
