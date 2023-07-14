#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_MASCOTAS 100
#define MAX_SERVICIOS 100

void MenuVeterinaria();
void ingresarMascota(int *numMascotas, int idMascotas[], char nombres[][50], char tipos[][50], int edades[], char duenos[][50]);
void ingresarServicio(int *numServicios, int idServicios[], char nombres[][50], char descripciones[][50], float precios[], int idMascotaServicio[]);
void facturarServicios(int numMascotas, int numServicios, int idMascotas[], char nombresMascotas[][50], char duenosMascotas[][50], int idServicios[], char nombresServicios[][50], char descripcionesServicios[][50], float preciosServicios[], int idMascotaServicio[]);

#endif
