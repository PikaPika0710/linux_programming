#include<stdlib.h>
int main(){
    int return_value;
    //System function returns exit status of shell. If shell doesn't run, it will return 127, 
    //else -1
    return_value = system("ls -l -i");
    return return_value;
}