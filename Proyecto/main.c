#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int op;
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

    FILE* archivo = fopen("facturacion.txt", "w"); // Abrir el archivo en modo escritura ("w")
    if (archivo == NULL) {
        printf("Error al abrir el archivo!!.\n");
        return 1;
    }
    fclose(archivo);

    do {
        MenuVeterinaria();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ingresar_Mascota(&numMascotas, idMascotas, nombresMascotas, tiposMascotas, edadesMascotas, duenosMascotas);
                break;
            case 2:
                ingresar_ServicioMacota(&numServicios, idServicios, nombresServicios, descripcionesServicios, preciosServicios, idMascotaServicio);
                break;
            case 3:
                modificar_ValorServicio(numServicios, idServicios, nombresServicios, preciosServicios);
                break;
            case 4:
                facturar_Servicios_Mascotas(numMascotas, numServicios, idMascotas, nombresMascotas, duenosMascotas, idServicios, nombresServicios, descripcionesServicios, preciosServicios, idMascotaServicio);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida!!!. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (op != 0);

    return 0;
}