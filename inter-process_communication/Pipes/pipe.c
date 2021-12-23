#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
//Ghi message vao stream voi count lan
void writter(const char* message, int count, FILE* stream){
    fprintf(stream, "%s\n", message);
    fflush(stream);
    sleep(1);
}

//Doc ngau nhien chuoi tu stream
void reader(FILE *stream){
    char buffer[1024];
    while(!feof(stream) && !ferror(stream) 
            && fgets(buffer, sizeof(buffer), stream) != NULL)
            {
                fputs(buffer,stdout);
            }
}

int main(){
    //Doc len phan tu 0 va ghi len phan tu 1
    int fds[2];   
    pid_t pid;
    pipe(fds); //Tao pipe
    pid =fork();//Tao tien trinh con
    if(pid == (pid_t)0){
        //Tien trinh con
        FILE* stream;
        //Dong dau ghi cua duong ong
        close(fds[1]);
        stream = fdopen(fds[0], "r");
        //Doc chuoi tu duong ong
        reader(stream);
        //Dong dau doc cua duong ong
        close(fds[0]);
    }
    else{
        //Tien trinh cha
        FILE *stream;
        //Dong dau doc cua duong ong 
        close(fds[0]);
        stream = fdopen(fds[1], "w");
        //Ghi chuoi vao duong ong
        writter("Hello, hello, hello!!!", 5, stream);
        //Dong dau ghi cua duong ong
        close(fds[1]);
    }
    return 0;
}