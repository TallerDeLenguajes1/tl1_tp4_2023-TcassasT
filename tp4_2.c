#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Tarea {
  int TareaID;
  char * Descripcion;
  int Duracion;
} Tarea;

int main() {
  // Seed rand()
  srand(time(NULL));

  int cantidadDeTareas = 0;
  printf("Ingrese la cantidad de tareas:");
  scanf("%d%*c", &cantidadDeTareas);

  Tarea ** matrizDeTareas = (Tarea **) malloc(cantidadDeTareas * sizeof(Tarea **));

  // Inicializa arrays en NULL
  int i;
  for(i = 0; i < cantidadDeTareas; i++) {
    matrizDeTareas[i] = NULL;
  }

  // Carga tareas
  for(i = 0; i < cantidadDeTareas; i++) {
    char * buffer = (char *) malloc(100 * sizeof(char *));
    matrizDeTareas[i] = (Tarea *) malloc(sizeof(Tarea *));

    // Asigna ID
    matrizDeTareas[i]->TareaID = i;

    // Asigna descripcion
    printf("Ingrese la descripción para tarea N° %d (max. 100 carateres):\n", i);
    matrizDeTareas[i]->Descripcion = (char *) malloc(100 * sizeof(char *));
    gets(buffer);
    strcpy(matrizDeTareas[i]->Descripcion, buffer);

    // Asigna duracion
    do {
      printf("Ingrese la duracion de la tarea N° %d:", i);
      scanf("%d%*c", &matrizDeTareas[i]->Duracion);

      if(matrizDeTareas[i]->Duracion <= 10 || matrizDeTareas[i]->Duracion >= 100) {
        printf("x La duracion de una tarea debe ser de entre 10 y 100, vuelva a intentarlo. ");
      }
    } while (matrizDeTareas[i]->Duracion <= 10 || matrizDeTareas[i]->Duracion >= 100);

    printf("\n");
  }

  Tarea ** tareasRealizadas = (Tarea **) malloc(cantidadDeTareas * sizeof(Tarea **));
  Tarea ** tareasNoRealizadas = (Tarea **) malloc(cantidadDeTareas * sizeof(Tarea **));

  printf("\n");

  for(i = 0; i < cantidadDeTareas; i++) {
    printf("-Tarea N° %d\n", matrizDeTareas[i]->TareaID);
    printf("\tDescripcion: %s\n", matrizDeTareas[i]->Descripcion);
    printf("\tDuracion: %d\n\n", matrizDeTareas[i]->Duracion);
  }

  return 0;
}


