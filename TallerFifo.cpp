#include <stdio.h>
#include <stdlib.h>

#define MAX_CORREDORES 100

void ordenarTiempos(float *tiempos, char **nombres, int n);
float calcularPromedio(float *tiempos, int n);
float calcularMediana(float *tiempos, int n);

int main() {
    char **nombres;
    float *tiempos;
    int n, i;

    printf("Ingrese el número de corredores: ");
    scanf("%d", &n);

    // Pedir memoria para los nombres y tiempos de los corredores
    nombres = (char**) malloc(n * sizeof(char*));
    tiempos = (float*) malloc(n * sizeof(float));

    // Pedir los nombres y tiempos de cada corredor
    for (i = 0; i < n; i++) {
        nombres[i] = (char*) malloc(50 * sizeof(char));
        printf("Ingrese el nombre del corredor %d: ", i+1);
        scanf("%s", nombres[i]);
        printf("Ingrese el tiempo en minutos del corredor %d: ", i+1);
        scanf("%f", &tiempos[i]);
    }

    // Ordenar los tiempos de menor a mayor
    ordenarTiempos(tiempos, nombres, n);

    // Mostrar los resultados
    printf("\nRESULTADOS DEL MARATÓN\n");
    printf("----------------------\n");

    printf("Posición\tNombre\t\tTiempo\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", i+1, nombres[i], tiempos[i]);
    }

    printf("\nPromedio de tiempo utilizado: %.2f minutos\n", calcularPromedio(tiempos, n));
    printf("Mediana de tiempo utilizado: %.2f minutos\n", calcularMediana(tiempos, n));

    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(nombres[i]);
    }
    free(nombres);
    free(tiempos);

    return 0;
}

void ordenarTiempos(float *tiempos, char **nombres, int n) {
    int i, j, minIndex;
    float tempTiempo;
    char *tempNombre;

    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (tiempos[j] < tiempos[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambiar los valores de los tiempos y nombres en las posiciones i y minIndex
        tempTiempo = tiempos[i];
        tiempos[i] = tiempos[minIndex];
        tiempos[minIndex] = tempTiempo;

        tempNombre = nombres[i];
        nombres[i] = nombres[minIndex];
        nombres[minIndex] = tempNombre;
    }
}

float calcularPromedio(float *tiempos, int n) {
    float sum = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        sum += tiempos[i];
    }

    return sum / n;
}

float calcularMediana(float *tiempos, int n) {
    float mediana;

    if (n % 2 == 0) {
        // Si hay un número par de elementos, la mediana es el promedio de los dos valores del centro
        int medio = n / 2;
        mediana = (tiempos[medio-1] + tiempos[medio]) / 2;
    } else {
        // Si hay un número impar de elementos, la mediana es el valor del centro
        mediana = tiempos[n/2];
    }

    return mediana;
}

//kris michael torres
//Erin kamila garces
