#include <stdlib.h>

struct materiaDictando
{
    char nombreMateria[50];
    int paralelo;
};

struct Profesor
{
    char nombre[50];
    char carrera[50];
    struct materiaDictando *NewMD;
    size_t cantidadMD;
};

// Estructura para el estudiante
struct materiaTomando
{
    char nombreMateria[50];
    int creditos;
};

struct Estudiante
{
    char nombre[50];
    int nivel;
    char carrera[50];
    struct materiaTomando *NewMT;
    size_t cantidadMT;
};