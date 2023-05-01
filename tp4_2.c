#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Tarea {
  int TareaID;
  char * Descripcion;
  int Duracion;
} Tarea;

// Funciones
void inicializaTareas(Tarea ** matrizDeTareas, int cantidadDeTareas);
void cargaTareas(Tarea ** matrizDeTareas, int cantidadDeTareas);
void mostrarTareas(Tarea ** matrizDeTareas, int cantidadDeTareas);
void administrarEstadoTareas(Tarea ** matrizDeTareas, int cantidadDeTareas, Tarea ** matrizDeTareasRealizadas);

int main() {
  // Seed rand()
  srand(time(NULL));

  int cantidadDeTareas = 0;
  printf("Ingrese la cantidad de tareas:");
  scanf("%d%*c", &cantidadDeTareas);

  Tarea ** matrizDeTareas = (Tarea **) malloc(cantidadDeTareas * sizeof(Tarea **));
  inicializaTareas(matrizDeTareas, cantidadDeTareas);

  cargaTareas(matrizDeTareas, cantidadDeTareas);
  mostrarTareas(matrizDeTareas, cantidadDeTareas);

  Tarea ** tareasRealizadas = (Tarea **) malloc(cantidadDeTareas * sizeof(Tarea **));
  inicializaTareas(tareasRealizadas, cantidadDeTareas);

  administrarEstadoTareas(matrizDeTareas, cantidadDeTareas, tareasRealizadas);

  printf("-Tareas luego de reorganizar:\n");
  mostrarTareas(tareasRealizadas, cantidadDeTareas);

  return 0;
}

void inicializaTareas(Tarea ** matrizDeTareas, int cantidadDeTareas) {
  int i;

  for(i = 0; i < cantidadDeTareas; i++) {
    matrizDeTareas[i] = NULL;
  }
}

void cargaTareas(Tarea ** matrizDeTareas, int cantidadDeTareas) {
  // Carga tareas
  int i;

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

      if(matrizDeTareas[i]->Duracion < 10 || matrizDeTareas[i]->Duracion > 100) {
        printf("x La duracion de una tarea debe ser de entre 10 y 100, vuelva a intentarlo. ");
      }
    } while (matrizDeTareas[i]->Duracion < 10 || matrizDeTareas[i]->Duracion > 100);

    printf("\n");
  }
}

void mostrarTareas(Tarea ** matrizDeTareas, int cantidadDeTareas) {
  int i;

  for(i = 0; i < cantidadDeTareas; i++) {
    if(matrizDeTareas[i] != NULL) {
      printf("\t-Tarea N° %d\n", matrizDeTareas[i]->TareaID);
      printf("\tDescripcion: %s\n", matrizDeTareas[i]->Descripcion);
      printf("\tDuracion: %d\n\n", matrizDeTareas[i]->Duracion);
    }
  }

  printf("\n");
}

void administrarEstadoTareas(Tarea ** matrizDeTareas, int cantidadDeTareas, Tarea ** matrizDeTareasRealizadas) {
  int i;
  int statusTareaAuxiliar;

  printf("A continuación se listarán todas las tareas y deberás indicar cuales fueron realizadas\n");
  for(i = 0; i < cantidadDeTareas; i++) {
    printf("-Tarea N° %d (%s) ", matrizDeTareas[i]->TareaID,  matrizDeTareas[i]->Descripcion);

    do {
      printf("¿Esta tarea fue realizada? (1: Si, 2: No): ");
      scanf("%d%*c", &statusTareaAuxiliar);

      if(statusTareaAuxiliar != 1 && statusTareaAuxiliar != 2) {
        printf("x Por favor elija una de las opciones mencionadas. ");
      }
      printf("\n");
    } while (statusTareaAuxiliar != 1 && statusTareaAuxiliar != 2);

    if(statusTareaAuxiliar == 1) {
      matrizDeTareasRealizadas[i] = (Tarea *) malloc(sizeof(Tarea *));
      matrizDeTareasRealizadas[i]->TareaID = matrizDeTareas[i]->TareaID;
      matrizDeTareasRealizadas[i]->Duracion = matrizDeTareas[i]->Duracion;
      matrizDeTareasRealizadas[i]->Descripcion = (char *) malloc(100 * sizeof(char *));
      strcpy(matrizDeTareasRealizadas[i]->Descripcion, matrizDeTareas[i]->Descripcion);
      
      free(matrizDeTareas[i]->Descripcion);
      matrizDeTareas[i] = NULL;
    }
  }
}