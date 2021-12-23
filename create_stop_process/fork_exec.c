#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int spawn(char * program, char* *arg_list){
    int child_pid = fork();
    if(child_pid<0){
        printf("Loi");
    }
    else if(child_pid!=0){
        return child_pid;
    }
    else{
        execvp(program, arg_list);
        fprintf(stderr, "Loi xay ra trong execvpn");
        abort();   
    }
}
int main(){
    char* arg_list[]={"ls", "-l", "/", NULL};
    spawn("ls", arg_list);
    sleep(1);
    printf("Ket thuc chuong trinh chinh!\n");
    return 0;
}