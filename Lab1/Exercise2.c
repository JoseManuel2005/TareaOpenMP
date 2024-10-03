    #include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int Array[100]; // Use rand() % 10000 for init
    /*
    Imprime el arreglo
    for (int i = 0; i < 100; i++) {
    printf("Prior the parallel region Array[%d] = %d\n", i, Array[i]);
    }*/

    //1
    #pragma omp parallel for
    for (int i = 0; i < 100; i++)
    {
        Array[i] =rand() % 10000;
    }

    for (int i = 0; i < 100; i++) {
    printf("Array[%d] = %d\n", i, Array[i]);
    }

    //2
    int max = 0;

    #pragma omp parallel for reduction(max:max)
    for (int i = 0; i < 100; i++) {
        if (Array[i] > max) {
            max = Array[i];
        }
    }
   
    printf("Max value is: %d\n", max);

    //3
    int min = 100000; 

    #pragma omp parallel for reduction(min:min)
    for (int i = 0; i < 100; i++) {
        if (Array[i] < min) {
            min = Array[i];
        }
    }

    printf("Min value is: %d\n", min);

    //4
    int avg;
    
    #pragma omp parallel
    {
    int local_add = 0;
    #pragma omp parallel for reduction(+:local_add)
    for (int i = 0; i < 100; i++) {
    local_add += Array[i];
    }
    avg = local_add/100;
    }
    printf("Now the avg is value is: %d\n", avg);

    
    return 0;
}