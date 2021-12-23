#include<pthread.h>
#include<stdio.h>
void* findPrime(void *pra){
    int pri = 2;
    int n = *((int*)pra);
    
    while(1){
        int nguyento=1;
        for(int i = 2; i<pri; i++){
            if(pri%i == 0){
                nguyento=0;
                break;
            }
        }
        if(nguyento){
            if(--n==0){
                return (void*) pri;
            }
        }
        pri++;
    }

    return NULL;
}
int main(){
    pthread_t p1;
    int prime;
    printf("\nNhap n:  ");
    int n;
    scanf("%d", &n);
    int m = n;
    pthread_create(&p1, NULL, &findPrime, &n);
    pthread_join(p1, (void*) &prime);
    printf("So nguyen to thu %d la %d!", m ,prime);
    return 0;
}

