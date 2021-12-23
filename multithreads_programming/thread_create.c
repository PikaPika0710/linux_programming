#include<pthread.h>
#include<stdio.h>
/*Ham in ra cac loi chuan, Tham so unused, ham khong tra ve gia tri*/
void * print_xs(void * unused){
    while (1)
    {
        fputc('x', stderr);
        
    }
    return NULL;
    
}
int main(){
    pthread_t thread_id; /*Tao mot ham moi chay ham print_xs()*/
    pthread_create (&thread_id, NULL, &print_xs, NULL); /*Ham print tiep tuc in chuoi 'o'*/
    while(1){
        fputc('o', stderr);
    }
    return 0;
}