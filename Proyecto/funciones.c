#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void MenuVeterinaria() {
    printf("*******************************************************\n");
    printf("*BIENVENIDO A LA VETERINARIA AMOR COMPRESION Y TERNURA*\n");
    printf("Menu de Servicios:\n");
    printf("1. Ingresar Mascota\n");
    printf("2. Ingresar Servicio\n");
    printf("3. Facturar Servicios\n");
    printf("0. Salir\n");
    printf("*******************************************************\n");
    printf("Seleccione una opcion: ");
    
}

void ingresarMascota(int *numMascotas, int idMascotas[], char nombres[][50], char tipos[][50], int edades[], char duenos[][50]) {
    if (*numMascotas >= MAX_MASCOTAS) {
        printf("No se pueden agregar mas mascotas.\n");
    } else {
        FILE* archivo = fopen("factura.txt", "a"); // Abrir el archivo en modo append ("a")
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }

        fprintf(archivo, "Ingreso de mascota:\n");

        printf("ID: ");
        scanf("%d", &idMascotas[*numMascotas]);
        fprintf(archivo, "ID: %d\n", idMascotas[*numMascotas]);

        printf("Nombre: ");
        scanf("%s", nombres[*numMascotas]);
        fprintf(archivo, "Nombre: %s\n", nombres[*numMascotas]);

        printf("Tipo: ");
        scanf("%s", tipos[*numMascotas]);
        fprintf(archivo, "Tipo: %s\n", tipos[*numMascotas]);

        printf("Edad: ");
        scanf("%d", &edades[*numMascotas]);
        fprintf(archivo, "Edad: %d\n", edades[*numMascotas]);

        printf("Dueño: ");
        scanf("%s", duenos[*numMascotas]);
        fprintf(archivo, "Dueno: %s\n", duenos[*numMascotas]);

        fprintf(archivo, "\n");

        fclose(archivo);

        (*numMascotas)++;
    }
}

void ingresarServicio(int *numServicios, int idServicios[], char nombres[][50], char descripciones[][50], float precios[], int idMascotaServicio[]) {
    if (*numServicios >= MAX_SERVICIOS) {
        printf("No se pueden agregar más servicios.\n");
    } else {
        FILE* archivo = fopen("factura.txt", "a"); // Abrir el archivo en modo append ("a")
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }

        fprintf(archivo, "Ingreso de servicio:\n");

        printf("ID: ");
        scanf("%d", &idServicios[*numServicios]);
        fprintf(archivo, "ID: %d\n", idServicios[*numServicios]);

        printf("Nombre: ");
        scanf("%s", nombres[*numServicios]);
        fprintf(archivo, "Nombre: %s\n", nombres[*numServicios]);

        printf("Descripcion: ");
        scanf("%s", descripciones[*numServicios]);
        fprintf(archivo, "Descripcion: %s\n", descripciones[*numServicios]);

        printf("Precio: ");
        scanf("%f", &precios[*numServicios]);
        fprintf(archivo, "Precio: %.2f\n", precios[*numServicios]);

        printf("ID de la mascota para el servicio: ");
        scanf("%d", &idMascotaServicio[*numServicios]);
        fprintf(archivo, "ID de la mascota para el servicio: %d\n", idMascotaServicio[*numServicios]);

        fprintf(archivo, "\n");

        fclose(archivo);

        (*numServicios)++;
    }
}

void facturarServicios(int numMascotas, int numServicios, int idMascotas[], char nombresMascotas[][50], char duenosMascotas[][50], int idServicios[], char nombresServicios[][50], char descripcionesServicios[][50], float preciosServicios[], int idMascotaServicio[]) {
    int idMascota;
    float precioTotalMascota = 0.0;
    int serviciosFacturados = 0;

    FILE* archivo = fopen("factura.txt", "a"); // Abrir el archivo en modo append ("a")
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "######## FACTURA ########\n");

    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &idMascota);
    fprintf(archivo, "ID de la mascota: %d\n", idMascota);

    // Verificar si el ID de la mascota es válido
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
        fprintf(archivo, "ID de mascota invalido.\n");
        fclose(archivo);
        return;
    }

    fprintf(archivo, "Mascota: %s\n", nombreMascota);
    fprintf(archivo, "Dueño: %s\n", nombreDueno);
    fprintf(archivo, "Servicios:\n");

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

            fprintf(archivo, "ID Servicio: %d\n", idServicio);
            fprintf(archivo, "Nombre: %s\n", nombreServicio);
            fprintf(archivo, "Precio por Servicio: %.2f\n", precioServicio);
            fprintf(archivo, "\n");

            precioTotalMascota += precioServicio;
            serviciosFacturados++;
        }
    }

    if (serviciosFacturados > 0) {
        fprintf(archivo, "Precio Total por Servicios: %.2f\n", precioTotalMascota);
    } else {
        fprintf(archivo, "La mascota no ha adquirido ningún servicio.\n");
    }

    fclose(archivo);
}
