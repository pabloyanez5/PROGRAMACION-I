#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarMascota(int *numMascotas, int idMascotas[], char nombres[][20], char tipos[][20], int edades[], char duenos[][20]) {
    if (*numMascotas >= MAX_MASCOTAS) {
        printf("No se pueden agregar mas mascotas.\n");
    } else {
        printf("Ingreso de mascota:\n");
        printf("ID: ");
        scanf("%d", &idMascotas[*numMascotas]);

        printf("Nombre: ");
        scanf("%s", nombres[*numMascotas]);

        printf("Tipo: ");
        scanf("%s", tipos[*numMascotas]);

        printf("Edad: ");
        scanf("%d", &edades[*numMascotas]);

        printf("Dueño: ");
        scanf("%s", duenos[*numMascotas]);

        (*numMascotas)++;
    }
}

void ingresarServicio(int *numServicios, int idServicios[], char nombres[][20], char descripciones[][20], float precios[], int idMascotaServicio[]) {
    if (*numServicios >= MAX_SERVICIOS) {
        printf("No se pueden agregar más servicios.\n");
    } else {
        printf("Ingreso de servicio:\n");
        printf("ID: ");
        scanf("%d", &idServicios[*numServicios]);

        printf("Nombre: ");
        scanf("%s", nombres[*numServicios]);

        printf("Descripcion: ");
        scanf("%s", descripciones[*numServicios]);

        printf("Precio: ");
        scanf("%f", &precios[*numServicios]);

        printf("ID de la mascota para el servicio: ");
        scanf("%d", &idMascotaServicio[*numServicios]);

        (*numServicios)++;
    }
}

void facturarServicios(int numMascotas, int numServicios, int idMascotas[], char nombresMascotas[][20], char duenosMascotas[][20], int idServicios[], char nombresServicios[][20], char descripcionesServicios[][20], float preciosServicios[], int idMascotaServicio[]) {
    int idMascota;
    float precioTotalMascota = 0.0;
    int serviciosFacturados = 0;

    printf("########### Facturar servicios ###########\n");

    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &idMascota);

    
    int mascotaEncontrada = 0;
    char nombreMascota[50];
    char nombreDueno[50];
    for (int i = 0; i < numMascotas; i++) {
        if (idMascotas[i] == idMascota) {
            mascotaEncontrada = 1;
            strcpy(nombreMascota, nombresMascotas[i]);
            strcpy(nombreDueno, duenosMascotas[i]);
            break;
        }
    }

    if (!mascotaEncontrada) {
        printf("ID de mascota invalido.\n");
        return;
    }

    printf("Mascota: %s\n", nombreMascota);
    printf("Dueño: %s\n", nombreDueno);
    printf("Servicios:\n");

    for (int i = 0; i < numServicios; i++) {
        if (idMascotaServicio[i] == idMascota) {
            int idServicio = idServicios[i];
            char nombreServicio[50];
            float precioServicio = preciosServicios[i];

            for (int j = 0; j < numServicios; j++) {
                if (idServicios[j] == idServicio) {
                    strcpy(nombreServicio, nombresServicios[j]);
                    break;
                }
            }

            printf("ID Servicio: %d\n", idServicio);
            printf("Nombre: %s\n", nombreServicio);
            printf("Precio por Servicio: %.2f\n", precioServicio);
            printf("\n");

            precioTotalMascota += precioServicio;
            serviciosFacturados++;
        }
    }

    if (serviciosFacturados > 0) {
        printf("Precio Total por Servicios: %.2f\n", precioTotalMascota);
    } else {
        printf("La mascota no ha adquirido ningún servicio.\n");
    }
}

