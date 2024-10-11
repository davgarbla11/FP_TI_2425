#include <stdio.h>
#include <string.h>
#define MAX_CAR 120
#define MAX_PLATOS 100
#define MAX_CLIENTES 100
#define MAX_PEDIDOS 100

int buscarPedidosCliente(int matrizPedidos[MAX_PEDIDOS][4], char clientes[MAX_CLIENTES][MAX_CAR], char nombreClienteBuscar[], int numPedidos, int numClientes, int vectorResultado[]);

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

    // Añadir Cliente //
    char nombreClienteBuscar[MAX_CAR];
    int vectorResultado[MAX_PEDIDOS];
    int numPedidosCliente, i, indiceResultado;

    printf("Introduzca el nombre del cliente: ");
    gets(nombreClienteBuscar);

    numPedidosCliente = buscarPedidosCliente(matrizPedidos, clientes, nombreClienteBuscar, numPedidos, numClientes, vectorResultado);

    if(numPedidosCliente == -1) {
        printf("Error: No se ha encontrado el cliente.\n");
    } else if(numPedidosCliente == 0) {
        printf("No se han encontrado pedidos para %s.\n", nombreClienteBuscar);
    } else {
        printf("\nPedidos de %s.\n\n", nombreClienteBuscar);
        for (i = 0; i < numPedidosCliente; i++) {
            indiceResultado = vectorResultado[i];
            if(matrizPedidos[indiceResultado][2] == 0){
                printf("- %s, Estado: Pendiente, Cantidad: %d\n\n", platos[matrizPedidos[indiceResultado][1]], matrizPedidos[indiceResultado][3]);
            } else if(matrizPedidos[indiceResultado][2] == 1){
                printf("- %s, Estado: En preparacion, Cantidad: %d\n\n", platos[matrizPedidos[indiceResultado][1]], matrizPedidos[indiceResultado][3]);
            } else {
                printf("- %s, Estado: Entregado, Cantidad: %d\n\n", platos[matrizPedidos[indiceResultado][1]], matrizPedidos[indiceResultado][3]);
            }
        }
    }

    return 0;
}

int buscarPedidosCliente(int matrizPedidos[MAX_PEDIDOS][4], char clientes[MAX_CLIENTES][MAX_CAR], char nombreClienteBuscar[], int numPedidos, int numClientes, int vectorResultado[]) {

    int i = 0, exito = 0, j, numIndice = 0;

    while(i < numClientes && !exito){
        if(strcmp(nombreClienteBuscar, clientes[i]) == 0){
            exito = 1;
        } else {
            i++;
        }
    }

    if(!exito) {
        return -1;
    } else {
        for(j = 0; j < numPedidos; j++){
            if(matrizPedidos[j][0] == i){
                vectorResultado[numIndice] = j;
                numIndice++;
            }
        }
        return numIndice;
    }
}