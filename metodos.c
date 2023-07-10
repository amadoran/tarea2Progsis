#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN_MAT_DIC 2
#define MAX_MAT_DIC 3
#define MIN_MAT_TOM 3
#define MAX_MAT_TOM 7

void getProfesor(struct Profesor **profesor, int cantidad)
{

    // Asignar memoria para arreglo structura PROFESOR
    *profesor = (struct Profesor *)calloc(cantidad, sizeof(struct Profesor));
    if (*profesor == NULL)
    {
        printf("Error al asignar memoria: Profesor.");
        exit(1);
    }

    // Ingresar datos del profesor
    for (int i = 0; i < cantidad; i++)
    {
        printf("REGISTRE PROFESOR #%d\n", i + 1);
        printf("- Nombre:\n");
        scanf("%s", (*profesor)[i].nombre);
        printf("- Carrera:\n");
        scanf("%s", (*profesor)[i].carrera);
        printf("- ¿Cuantas materias desea registrar?:\n");
        scanf("%zu", &((*profesor)[i].cantidadMD));
        while ((*profesor)[i].cantidadMD < MIN_MAT_DIC ||
               (*profesor)[i].cantidadMD > MAX_MAT_DIC)
        {
            printf("- Ingrese una cantidad válida de 2 a 3:\n");
            scanf("%zu", &((*profesor)[i].cantidadMD));
        }
        getMateriaDic(&((*profesor)[i].NewMD), (*profesor)[i].cantidadMD);
    }
};

void getMateriaDic(struct materiaDictando **materiasDict,
                   size_t cantidadMateriasD)
{

    // Asignar memoria para arreglo structura MATERIA DICTANDO
    *materiasDict = (struct materiaDictando *)calloc(
        cantidadMateriasD, sizeof(struct materiaDictando));
    if (*materiasDict == NULL)
    {
        printf("Error al asignar memoria: Profesor.");
        exit(1);
    }

    // Ingresar datos del Materia Dictando
    for (int i = 0; i < cantidadMateriasD; i++)
    {
        printf("REGISTRE MATERIA #%d PARA PROFESOR\n", i + 1);
        printf("- Nombre de Materia:\n");
        scanf("%s", (*materiasDict)[i].nombreMateria);
        printf("- Paralelo:\n");
        scanf("%d", &(*materiasDict)[i].paralelo);
    }
};

void getEstudiante(struct Estudiante **estudiante, int cantidad)
{

    // Asignar memoria para arreglo structura PROFESOR
    *estudiante = (struct Estudiante *)calloc(cantidad, sizeof(struct Estudiante));
    if (*estudiante == NULL)
    {
        printf("Error al asignar memoria: Estudiante.");
        exit(1);
    }

    // Ingresar datos del profesor
    for (int i = 0; i < cantidad; i++)
    {
        printf("REGISTRE ESTUDIANTE #%d\n", i + 1);
        printf("- Nombre:\n");
        scanf("%s", (*estudiante)[i].nombre);
        printf("- Nivel:\n");
        scanf("%d", &((*estudiante)[i].nivel));
        printf("- Carrera:\n");
        scanf("%s", (*estudiante)[i].carrera);
        printf("- ¿Cuantas materias desea registrar?:\n");
        scanf("%zu", &((*estudiante)[i].cantidadMT));
        while (MIN_MAT_TOM > (*estudiante)[i].cantidadMT ||
               MAX_MAT_TOM < (*estudiante)[i].cantidadMT)
        {
            printf("Ingrese una cantidad válida de 3 a 7:\n");
            scanf("%zu", &((*estudiante)[i].cantidadMT));
        }
        getMateriaTomando(&((*estudiante)[i].NewMT), (*estudiante)[i].cantidadMT);
    }
};

void getMateriaTomando(struct materiaTomando **materiasTom,
                       size_t cantidadMateriasT)
{

    // Asignar memoria para arreglo structura MATERIA DICTANDO
    *materiasTom = (struct materiaTomando *)calloc(cantidadMateriasT,
                                                   sizeof(struct materiaTomando));
    if (*materiasTom == NULL)
    {
        printf("Error al asignar memoria: Profesor.");
        exit(1);
    }

    // Ingresar datos del Materia Dictando
    for (int i = 0; i < cantidadMateriasT; i++)
    {
        printf("REGISTRE MATERIA #%d PARA ESTUDIANTE\n", i + 1);
        printf("- Nombre de Materia:\n");
        scanf("%s", (*materiasTom)[i].nombreMateria);
        printf("- Paralelo:\n");
        scanf("%d", &((*materiasTom)[i].creditos));
    }
};

void mostrarProfesores(struct Profesor *p, int cantidad)
{
    printf("Profesores:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre: %s\n", p[i].nombre);
        printf("Carrera: %s\n", p[i].carrera);
        mostrarMD(p[i].NewMD, p[i].cantidadMD);
    }
}

void mostrarMD(struct materiaDictando *md, size_t cantidad)
{
    printf("\tMaterias Dictando:\n");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("\tNombre: %s\n", md[i].nombreMateria);
        printf("\tParalelo: %i\n", md[i].paralelo);
    }
}

void mostrarEstudiantes(struct Estudiante *e, int cantidad)
{
    printf("Estudiantes:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre: %s\n", e[i].nombre);
        printf("Nivel: %i\n", e[i].nivel);
        printf("Carrera: %s\n", e[i].carrera);
        mostrarMT(e[i].NewMT, e[i].cantidadMT);
    }
}

void mostrarMT(struct materiaTomando *mt, size_t cantidad)
{
    printf("\tMaterias Tomando:\n");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("\tNombre: %s\n", mt[i].nombreMateria);
        printf("\tCreditos: %i\n", mt[i].creditos);
    }
}