Uso de las librerias
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char nombre[MAX];
    char direccion[MAX];
    char cedula[MAX];
    char marca[MAX];
    char modelo[MAX];
    char observaciones[MAX];
    int tipoTrabajo;
    float costo;
} Orden;

const float COSTOS[] = {50.0, 100.0, 200.0};

Orden *crearOrden()
{
    Orden *o = (Orden *)malloc(sizeof(Orden));

    printf("Ingrese su nombre: ");
    fgets(o->nombre, MAX, stdin);
    o->nombre[strcspn(o->nombre, "\n")] = 0;

    printf("Ingrese su direccion: ");
    fgets(o->direccion, MAX, stdin);
    o->direccion[strcspn(o->direccion, "\n")] = 0;

    printf("Ingrese su cedula: ");
    fgets(o->cedula, MAX, stdin);
    o->cedula[strcspn(o->cedula, "\n")] = 0;
    printf("Ingrese la marca de su computadora: ");
    fgets(o->marca, MAX, stdin);
    o->marca[strcspn(o->marca, "\n")] = 0;
Hasta la linea treinta y siete se definio una estructura de orden, que contiene ordenes de trabajo

    printf("Ingrese el modelo de su computadora: ");
    fgets(o->modelo, MAX, stdin);
    o->modelo[strcspn(o->modelo, "\n")] = 0;

    printf("Ingrese alguna observacion a tener en cuenta para el servicio de su computadora: ");
    fgets(o->observaciones, MAX, stdin);
    o->observaciones[strcspn(o->observaciones, "\n")] = 0;

    printf("Ingrese el tipo de trabajo (0: mantenimiento, 1: reparacion, 2: actualizacion): ");
    scanf("%d", &(o->tipoTrabajo));
    getchar();

    o->costo = COSTOS[o->tipoTrabajo];

    printf("El costo de este servicio sera: $%.2f\n", o->costo);

    return o;
}

void guardarOrden(Orden *o)
{
    FILE *file = fopen("ordenes.txt", "a");

    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%s,%s,%s,%d,$%.2f\n",
            o->nombre,
            o->direccion,
            o->cedula,
            o->marca,
            o->modelo,
            o->observaciones,
            o->tipoTrabajo,
            o->costo);

    fclose(file);
}

int main()
{
    while (1)
    {
        printf("\nMENU\n");
        printf("1. Crear orden de trabajo\n");
        printf("2. Salir\n");
        printf("Seleccione una opcion: ");

        int opcion;
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1)
        {
            Orden *o = crearOrden();
            guardarOrden(o);
            free(o);
        }
        else if (opcion == 2)
        {
            break;
        }
        else
        {
            printf("Opcion no valida\n");
        }
    }

    return 0;
}
