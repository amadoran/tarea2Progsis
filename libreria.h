// Estructura para el profesor
#include <stdio.h>
#include "estructuras.c"

void getMateriaDic(struct materiaDictando **materiasDict, size_t cantidadMateriasD);
void getProfesor(struct Profesor **profesor, int cantidad);
void getEstudiante(struct Estudiante **estudiante, int cantidad);
void getMateriaTomando(struct materiaTomando **materiasTom, size_t cantidadMateriasT);
void mostrarProfesores(struct Profesor *p, int cantidad);
void mostrarMD(struct materiaDictando *md, size_t cantidad);
void mostrarEstudiantes(struct Estudiante *e, int cantidad);
void mostrarMT(struct materiaTomando *mt, size_t cantidad);
