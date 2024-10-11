#include <stdio.h>
#include <string.h>
#define MAX_CAR 120
#define MAX_PLATOS 100
#define MAX_CLIENTES 100
#define MAX_PEDIDOS 100


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

    int i;

    printf("Pendientes:\n\n");

    for(i = 0; i < numPedidos; i++) {
        if(matrizPedidos[i][2] == 0){
            printf("Cliente: %s, Plato: %s, Cantidad: %d\n\n", clientes[matrizPedidos[i][0]], platos[matrizPedidos[i][1]], matrizPedidos[i][3]);
        }
    }

    printf("En preparacion:\n\n");

    for(i = 0; i < numPedidos; i++) {
        if(matrizPedidos[i][2] == 1){
            printf("Cliente: %s, Plato: %s, Cantidad: %d\n\n", clientes[matrizPedidos[i][0]], platos[matrizPedidos[i][1]], matrizPedidos[i][3]);
        }
    }

    printf("Entregados:\n\n");

    for(i = 0; i < numPedidos; i++) {
        if(matrizPedidos[i][2] == 2){
            printf("Cliente: %s, Plato: %s, Cantidad: %d\n\n", clientes[matrizPedidos[i][0]], platos[matrizPedidos[i][1]], matrizPedidos[i][3]);
        }
    }

    return 0;

}