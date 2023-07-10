TARGET = regDO

all: $(TARGET)

regDO: estructuras.o metodos.o regDatosOpciones.o
	gcc regDatosOpciones.o metodos.o estructuras.o -o $(TARGET)

regDatosOpciones.o: regDatosOpciones.c libreria.h
	gcc -c regDatosOpciones.c

metodos.o: metodos.c libreria.h
	gcc -c metodos.c

estructuras.o: estructuras.c
	gcc -c estructuras.c

clean:
	rm -f *.o $(TARGET)
