#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
#define SO_THREAD   4
void *InLoiChao(void *threadid)
{
   cout << "Hello World! Thread ID la " << threadid << endl;
   pthread_exit(NULL);
}
int main ()
{
   pthread_t threads[SO_THREAD];
   int rc;
   int i;
   for( i=0; i < SO_THREAD; i++ ){
      cout << "\nmain() : dang tao thread! " << i << endl;
      rc = pthread_create(&threads[i], NULL, 
                          InLoiChao, (int *)i);
      if (rc){
         cout << "\nError: Khong the tao thread!" << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}