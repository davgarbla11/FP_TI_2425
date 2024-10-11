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

    // Ejercicio

    int i = 0, j = 0, exito = 0, estadoPedido, cantidadUsuario;
    char clienteUsuario[MAX_CAR];
    char platoUsuario[MAX_CAR]; 

    printf("Introduzca el nombre del cliente: ");
    gets(clienteUsuario);

    while(i < numClientes && !exito){
        if(strcmp(clienteUsuario, clientes[i]) == 0){
            exito = 1;
        } else {
            i++;
        }
    }

    if(!exito) {
        printf("Error: Cliente no registrado\n");
    } else {
        printf("Introduzca el nombre del plato: ");
        gets(platoUsuario);
        exito = 0;

        while(j < numPlatos && !exito){
            if(strcmp(platoUsuario, platos[j]) == 0) {
                exito = 1;
            } else {
                j++;
            }
        }

        if(!exito){
            printf("Error: Plato no encontrado.\n");
        } else {
            printf("Introduzca el estado del pedido (0: Pendiente, 1: En preparacion, 2: Entregado): ");
            scanf("%d", &estadoPedido);
            printf("Introduzca la cantidad solicitada: ");
            scanf("%d", &cantidadUsuario);

            matrizPedidos[numPedidos][0] == i;
            matrizPedidos[numPedidos][1] == j;
            matrizPedidos[numPedidos][2] == estadoPedido;
            matrizPedidos[numPedidos][3] == cantidadUsuario;

            numPedidos++;

            printf("Pedido añadido correctamente.");
        }

    }
    
    return 0;
}