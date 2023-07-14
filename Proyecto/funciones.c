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
    printf("3. Modificar Valor del Servicio\n");
    printf("4. Facturar Servicios\n");
    printf("0. Salir\n");
    printf("*******************************************************\n");
    printf("Seleccione una opcion: ");
    
}

void ingresar_Mascota(int *numMascotas, int idMascotas[], char nombres[][50], char tipos[][50], int edades[], char duenos[][50]) {
    if (*numMascotas >= MAX_MASCOTAS) {
        printf("No se pueden agregar mas mascotas.\n");
    } else {
        FILE* archivo = fopen("facturacion.txt", "a"); // Abrir el archivo en modo append ("a")
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

void ingresar_ServicioMacota(int *numServicios, int idServicios[], char nombres[][50], char descripciones[][50], float precios[], int idMascotaServicio[]) {
    if (*numServicios >= MAX_SERVICIOS) {
        printf("No se pueden agregar más servicios.\n");
    } else {
        FILE* archivo = fopen("facturacion.txt", "a"); // Abrir el archivo en modo append ("a")
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
void modificar_ValorServicio(int numServicios, int idServicios[], char nombresServicios[][50], float preciosServicios[]) {
    int idServicio;
    float nuevoPrecioServicio;

    printf("Modificar valor del servicio:\n");
    printf("Ingrese el ID del servicio: ");
    scanf("%d", &idServicio);

    int servicioEncontrado = 0;
    for (int i = 0; i < numServicios; i++) {
        if (idServicios[i] == idServicio) {
            printf("Servicio encontrado:\n");
            printf("ID Servicio: %d\n", idServicio);
            printf("Nombre: %s\n", nombresServicios[i]);
            printf("Precio actual: %.2f\n", preciosServicios[i]);

            printf("Ingrese el nuevo precio: ");
            scanf("%f", &nuevoPrecioServicio);

            preciosServicios[i] = nuevoPrecioServicio;

            printf("El valor del servicio se ha modificado con éxito.\n");

            servicioEncontrado = 1;
            break;
        }
    }

    if (!servicioEncontrado) {
        printf("ID de servicio invalido.\n");
    }
}
void facturar_Servicios_Mascotas(int numMascotas, int numServicios, int idMascotas[], char nombresMascotas[][50], char duenosMascotas[][50], int idServicios[], char nombresServicios[][50], char descripcionesServicios[][50], float preciosServicios[], int idMascotaServicio[]) {
    int idMascota;
    float precioTotalMascota = 0.0;
    int serviciosFacturados = 0;

    printf("######## FACTURA ########\n");

    printf("Ingrese el ID de la mascota que desea la Factura: ");
    scanf("%d", &idMascota);

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
        return;
    }

    printf("Mascota: %s\n", nombreMascota);
    printf("Dueño: %s\n", nombreDueno);
    printf("Servicios:\n");

    FILE* archivo = fopen("facturacion.txt", "a");
    fprintf(archivo, "######## FACTURA ########\n");
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

            printf("ID Servicio: %d\n", idServicio);
            printf("Nombre: %s\n", nombreServicio);
            printf("Precio por Servicio: %.2f$\n", precioServicio);
            printf("\n");

            fprintf(archivo, "ID Servicio: %d\n", idServicio);
            fprintf(archivo, "Nombre: %s\n", nombreServicio);
            fprintf(archivo, "Precio por Servicio: %.2f$\n", precioServicio);
            fprintf(archivo, "\n");

            precioTotalMascota += precioServicio;
            serviciosFacturados++;
        }
    }

    if (serviciosFacturados > 0) {
        printf("Precio Total por Servicios: %.2f$\n", precioTotalMascota);
        fprintf(archivo, "Precio Total por Servicios: %.2f$\n", precioTotalMascota);
    } else {
        printf("La mascota no ha adquirido ningún servicio en esta veterinaria!!.\n");
        fprintf(archivo, "La mascota no ha adquirido ningún servicio en esta veterinaria!!.\n");
    }

    fclose(archivo);
}