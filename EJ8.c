#include <stdio.h>
#include <string.h>
#define MAX_CAR 120
#define MAX_PLATOS 100
#define MAX_CLIENTES 100
#define MAX_PEDIDOS 100

void calcularDemandaPlatos(int matrizPedidos[MAX_PEDIDOS][4], int numPedidos, int numPlatos, int demandas[]);
int encontrarPlatoMasDemandado(int demandas[], int numPlatos);

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
    int demandas[MAX_PLATOS];
    int indicePlatoDemandado;

    calcularDemandaPlatos(matrizPedidos, numPedidos, numPlatos, demandas);
    indicePlatoDemandado = encontrarPlatoMasDemandado(demandas, numPlatos);

    printf("El plato mas demandado es: %s\n\n", platos[indicePlatoDemandado]);
    printf("Cantidad total solicitada: %d unidades\n", demandas[indicePlatoDemandado]);

    return 0;

}

void calcularDemandaPlatos(int matrizPedidos[MAX_PEDIDOS][4], int numPedidos, int numPlatos, int demandas[]) {
    int i, j, suma;

    for(i = 0; i < numPlatos; i++){
        suma = 0;
        for(j = 0; j < numPedidos; j++){
            if(matrizPedidos[j][1] == i){
                suma += matrizPedidos[j][3];
            }
        }
        demandas[i] = suma;
    }
}

int encontrarPlatoMasDemandado(int demandas[], int numPlatos){
    int i, indiceMayor = 0, mayor = 0;

    for(i = 0; i < numPlatos; i++) {
        if(demandas[i] > mayor){
            mayor = demandas[i];
            indiceMayor = i;
        }
    }

    return indiceMayor;
}