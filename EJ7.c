#include <stdio.h>
#include <string.h>
#define MAX_CAR 120
#define MAX_PLATOS 100
#define MAX_CLIENTES 100
#define MAX_PEDIDOS 100

float calcularTotalCliente(int matrizPedidos[MAX_PEDIDOS][4], char clientes[MAX_CLIENTES][MAX_CAR], float precios[], int numClientes, int numPedidos, char nombreClienteBuscar[MAX_CAR]);

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
    float totalApagar;
    char nombreClienteBuscar[MAX_CAR];
    printf("Introduce el nombre del cliente: ");
    gets(nombreClienteBuscar);

    totalApagar = calcularTotalCliente(matrizPedidos, clientes, precios, numClientes, numPedidos, nombreClienteBuscar);
    
    if(totalApagar < 0) {
        printf("Error: No se ha podido encontrar al cliente.\n");
    } else {
        printf("\n\nEl total a pagar por %s es: %5.2f euros", nombreClienteBuscar, totalApagar);
    }

    return 0;

}

float calcularTotalCliente(int matrizPedidos[MAX_PEDIDOS][4], char clientes[MAX_CLIENTES][MAX_CAR], float precios[], int numClientes, int numPedidos, char nombreClienteBuscar[MAX_CAR]) {
    float resultado = 0, precioTemporal;
    int i = 0, j, exito = 0, cantidadTemporal, indicePlatoTemporal;

    while(i < numClientes && !exito) {
        if(strcmp(nombreClienteBuscar, clientes[i]) == 0){
            exito = 1;
        } else {
            i++;
        }
    }

    if(!exito) {
        return -1;
    } else {
        for(j = 0; j < numPedidos; j++) {
            if(matrizPedidos[j][0] == i){
                cantidadTemporal = matrizPedidos[j][3];
                indicePlatoTemporal = matrizPedidos[j][1];
                precioTemporal = cantidadTemporal * precios[indicePlatoTemporal];
                resultado += precioTemporal;
            }
        }

        return resultado;
    }
}