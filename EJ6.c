#include <stdio.h>
#include <string.h>
#define MAX_CAR 120
#define MAX_PLATOS 100
#define MAX_CLIENTES 100
#define MAX_PEDIDOS 100

int buscarPedidosPlato(int matrizPedidos[MAX_PEDIDOS][4], char platos[MAX_PLATOS][MAX_CAR], char nombrePlatoBuscar[], int numPlatos, int numPedidos, int vectorResultado[]);

int main(){
    char platos[MAX_PLATOS][MAX_CAR] = {"Ensalada Cesar", "Pizza Margarita", "Hamburguesa con queso", "Sopa de Tomate", "Spaguetti Bolognese"};
    float precios[MAX_PLATOS] = {8.50, 9.00, 11.50, 5.50, 12.00};
    char clientes[MAX_CLIENTES][MAX_CAR] = {"Juan Perez", "Maria Garcia", "Carlos Sanchez", "Lucia Fernandez"};
    int matrizPedidos[MAX_PEDIDOS][4] = 
    {
        {0, 1, 2, 2},
        {1, 0, 1, 1},
        {2, 3, 0, 3},
        {3, 4, 2, 1},
        {1, 1, 0, 2},
        {0, 3, 2, 3}
    };
    int numPlatos = 5, numClientes = 4, numPedidos = 6;

    // Ejercicio //
    int i, tamVecRes;
    int vectorResultado[MAX_PEDIDOS];
    char nombrePlatoBuscar[MAX_CAR];

    printf("Introduzca el nombre del plato: ");
    gets(nombrePlatoBuscar);

    tamVecRes = buscarPedidosPlato(matrizPedidos, platos, nombrePlatoBuscar, numPlatos, numPedidos, vectorResultado);

    if(tamVecRes == -1) {
        printf("Error: Plato no encontrado.\n");
    } else if(tamVecRes == 0) {
        printf("No se han encontrado pedidos para el plato: %s\n", nombrePlatoBuscar);
    } else {
        printf("\nPedidos de %s\n\n", nombrePlatoBuscar);
        for( i = 0; i < tamVecRes; i++){
            if(matrizPedidos[vectorResultado[i]][2] == 0){
                printf("- Cliente: %s, Cantidad: %d, Estado: Pendiente\n\n", clientes[matrizPedidos[vectorResultado[i]][0]], matrizPedidos[vectorResultado[i]][3]);
            } else if(matrizPedidos[vectorResultado[i]][2] == 1){
                printf("- Cliente: %s, Cantidad: %d, Estado: En preparacion\n\n", clientes[matrizPedidos[vectorResultado[i]][0]], matrizPedidos[vectorResultado[i]][3]);
            } else {
                printf("- Cliente: %s, Cantidad: %d, Estado: Entregado\n\n", clientes[matrizPedidos[vectorResultado[i]][0]], matrizPedidos[vectorResultado[i]][3]);
            }
        }
    }
    
    return 0;
}

int buscarPedidosPlato(int matrizPedidos[MAX_PEDIDOS][4], char platos[MAX_PLATOS][MAX_CAR], char nombrePlatoBuscar[], int numPlatos, int numPedidos, int vectorResultado[]){
    int i = 0, j, exito = 0, indiceVecRes = 0;

    while(i < numPlatos && !exito) {
        if(strcmp(nombrePlatoBuscar, platos[i]) == 0){
            exito = 1;
        } else {
            i++;
        }
    }

    if(!exito){
        return -1;
    } else {
        for(j = 0; j < numPedidos; j++){
            if(matrizPedidos[j][1] == i){
                vectorResultado[indiceVecRes] = j;
                indiceVecRes++; 
            }
        }
        return indiceVecRes;
    }
}

