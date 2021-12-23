#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;


void* prime_thread(void* arg) {
    int prime = 2;
    int count = 0;
    int n = *((int *) arg);
    printf("%d\n",n);
    while (1) {
        int nguyento = 1;
        for (int i = 2; i < prime; i++) {
            if (prime % i == 0) {
                nguyento = 0;
                break;
            }
        }
        if (nguyento) count++;
        if (nguyento) {
            if (count == n) {
                printf("Ket qua so nguyen to thu %d la %d\n",n,prime);
                return (void *) prime;
            }
        }
        prime++;
    }
    return NULL;
}

int main() {
    int n;
    printf("\nNhap n : "); scanf("%d",&n);
    pthread_t pthread_arr[n];
    pthread_t *pt = pthread_arr;
    int prime_arr[n];
    int *pp = prime_arr;
    int count = 1;

    for (int i=1;i<=n;i++){
        int *a = new int;
        //int b = i;
        //int *a = &b;
        *(a) = i;
        pthread_create((pt+i-1),NULL,&prime_thread,a);
    }
    for (int i=1;i<=n;i++)
    {
        pthread_join(*(pt+i-1), (void **)(pp+i-1));      
    }
    
    for (int i=0;i<n;i++) 
        printf("%d ", prime_arr[i]);
        printf("\n");
    return 0;
}