#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Forma de uso: %s numero \n", argv[0]);
        exit(-1);
    }
    
    int size = atoi(argv[1]);

    int A[size][size], B[size][size], C[size][size];
    //int A[10][10], B[10][10], C[10][10] = {0};
    int i, j, k;
    srand(time(NULL)); //inicializa random generator

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }
    clock_t begin, end;
    double time_spent;
    begin = clock();

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            for (k = 0; k < size; k++)
                C[i][j] += A[i][k] * B[k][j];

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2lf seconds.\n", time_spent);
    return 0;
}
