#include <stdio.h>
#include <string.h>

int main() {
    int estudiantes = 5;
    int asignaturas = 3;

    char nombres[5][50];  
    float calificaciones[5][3];
    float sumaTotal = 0;  
    int totalCalificaciones = estudiantes * asignaturas;

   
    for (int i = 0; i < estudiantes; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", nombres[i]);
    }

    
    for (int i = 0; i < estudiantes; i++) {
        for (int j = 0; j < asignaturas; j++) {
            do {
            printf("Ingrese la calificacion de %s en la asignatura %d (0-10): ", nombres[i], j + 1);
            scanf("%f", &calificaciones[i][j]);
            if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
        printf("Error: La calificacion es invalida. Debe estar entre 0 y 10.\n");
    }
            }while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
            sumaTotal += calificaciones[i][j];
            
        }
    }


    for (int i = 0; i < estudiantes; i++) {
        float sumaEstudiante = 0;
        float maxNota = calificaciones[i][0];  

        for (int j = 0; j < asignaturas; j++) {
            sumaEstudiante += calificaciones[i][j];

          
            if (calificaciones[i][j] > maxNota) {
                maxNota = calificaciones[i][j];
            }
        }

        float promedioEstudiante = sumaEstudiante / asignaturas;

        printf("\n%s: Promedio = %.2f, Nota mas alta = %.2f", nombres[i], promedioEstudiante, maxNota);

       
        if (promedioEstudiante >= 6)
            printf(" - APROBADO");
        else
            printf(" - REPROBADO");
    }

  
    for (int j = 0; j < asignaturas; j++) {
        float sumaAsignatura = 0;
        for (int i = 0; i < estudiantes; i++) {
            sumaAsignatura += calificaciones[i][j];
        }
        printf("\n\nAsignatura %d: Promedio = %.2f", j + 1, sumaAsignatura / estudiantes);
    }

    
    printf("\n\nPromedio general de todas las calificaciones: %.2f", sumaTotal / totalCalificaciones);

    

return 0;
}