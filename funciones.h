#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_MASCOTAS 100
#define MAX_SERVICIOS 100

void ingresarMascota(int *numMascotas, int idMascotas[], char nombres[][20], char tipos[][20], int edades[], char duenos[][20]);
void ingresarServicio(int *numServicios, int idServicios[], char nombres[][20], char descripciones[][20], float precios[], int idMascotaServicio[]);
void facturarServicios(int numMascotas, int numServicios, int idMascotas[], char nombresMascotas[][20], char duenosMascotas[][20], int idServicios[], char nombresServicios[][20], char descripcionesServicios[][20], float preciosServicios[], int idMascotaServicio[]);

#endif
