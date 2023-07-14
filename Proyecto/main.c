#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int opcion;
    int numMascotas = 0;
    int numServicios = 0;
    int idMascotas[MAX_MASCOTAS];
    int idServicios[MAX_SERVICIOS];
    char nombresMascotas[MAX_MASCOTAS][50];
    char tiposMascotas[MAX_MASCOTAS][50];
    int edadesMascotas[MAX_MASCOTAS];
    char duenosMascotas[MAX_MASCOTAS][50];
    char nombresServicios[MAX_SERVICIOS][50];
    char descripcionesServicios[MAX_SERVICIOS][50];
    float preciosServicios[MAX_SERVICIOS];
    int idMascotaServicio[MAX_SERVICIOS];

    FILE* archivo = fopen("factura.txt", "w"); // Abrir el archivo en modo escritura ("w")
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    fclose(archivo);

    do {
        MenuVeterinaria();
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