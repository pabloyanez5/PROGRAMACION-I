#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_MASCOTAS 100
#define MAX_SERVICIOS 100

void MenuVeterinaria();
void ingresar_Mascota(int *numMascotas, int idMascotas[], char nombres[][50], char tipos[][50], int edades[], char duenos[][50]);
void ingresar_ServicioMacota(int *numServicios, int idServicios[], char nombres[][50], char descripciones[][50], float precios[], int idMascotaServicio[]);
void modificar_ValorServicio(int numServicios, int idServicios[], char nombresServicios[][50], float preciosServicios[]);
void facturar_Servicios_Mascotas(int numMascotas, int numServicios, int idMascotas[], char nombresMascotas[][50], char duenosMascotas[][50], int idServicios[], char nombresServicios[][50], char descripcionesServicios[][50], float preciosServicios[], int idMascotaServicio[]);

#endif
