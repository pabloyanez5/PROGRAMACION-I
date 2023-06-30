#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    int numMascotas = 0;
    int numServicios = 0;
    int idMascotas[MAX_MASCOTAS];
    int idServicios[MAX_SERVICIOS];
    char nombresMascotas[MAX_MASCOTAS][20];
    char tiposMascotas[MAX_MASCOTAS][20];
    int edadesMascotas[MAX_MASCOTAS];
    char duenosMascotas[MAX_MASCOTAS][20];
    char nombresServicios[MAX_SERVICIOS][20];
    char descripcionesServicios[MAX_SERVICIOS][20];
    float preciosServicios[MAX_SERVICIOS];
    int idMascotaServicio[MAX_SERVICIOS];

    do {
        printf("Menu:\n");
        printf("1. Ingresar Mascota\n");
        printf("2. Ingresar Servicio\n");
        printf("3. Facturar Servicios\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarMascota(&numMascotas, idMascotas, nombresMascotas, tiposMascotas, edadesMascotas, duenosMascotas);
                break;
            case 2:
                ingresarServicio(&numServicios, idServicios, nombresServicios, descripcionesServicios, preciosServicios, idMascotaServicio);
                break;
            case 3:
                facturarServicios(numMascotas, numServicios, idMascotas, nombresMascotas, duenosMascotas, idServicios, nombresServicios, descripcionesServicios, preciosServicios, idMascotaServicio);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
