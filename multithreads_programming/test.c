#include<pthread.h>
#include<stdio.h>

struct a{
    int count;
    char character;
};
void *print(void *para){
    struct a *p = (struct a *) para;
    for(int i = 0; i<p->count;i++){
        fputc(p->character, stderr);
    }
    printf("\n");
    return NULL;
}
int main(){
    pthread_t p1;
    pthread_t p2;
    struct a pp1;
    struct a pp2;
    pp1.character='h';
    pp1.count = 10;
    pp2.character='v';
    pp2.count = 20;
    pthread_create(&p1, NULL, &print, &pp1);
    pthread_create(&p2, NULL, &print, &pp2);

    pthread_join(p1, NULL); 
    pthread_join(p2, NULL);

    return 0;
}
