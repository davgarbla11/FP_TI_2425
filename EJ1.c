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

    // Añadir Plato //

    if(numPlatos == MAX_PLATOS) {
        printf("No se pueden añadir mas platos.\n");
    } else{
        printf("Introduzca el nombre del plato: ");
        gets(platos[numPlatos]);
        printf("Introduzca el precio del plato a añadir: ");
        scanf("%f", &precios[numPlatos]);
        numPlatos++;
        printf("Plato añadido correctamente. Ahora hay %d platos en el sistema.\n", numPlatos);
    }

    return 0;

}