#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(22)
    {
        if (omp_get_thread_num()%2 == 0){
         printf("Hi, I am a even number, my ID is: %d\n", omp_get_thread_num());
        } else {
         printf("Hi, I am a odd number, my ID is: %d\n", omp_get_thread_num());
        } 
    }
    return 0;
}