#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

void *xuly(void *arg)
{
    int rs = 1023;
    int n = *((int *)arg);
    int start = n * 1024;
    int end = n * 1024 + 1024 - 1;

    cout << "\n Thread " << n << " xu ly cac phan tu: " << start << " den " << end << endl;
    long sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += i;
    }
    if (sum != 0)
    {
        return (void *)sum;
    }
    return NULL;
}
int main()
{
    cout << "***********************************************" << endl;
    cout << "* Ho va ten : Tran Cong Viet                    *" << endl;
    cout << "* Nhom:19Nh10                                   *" << endl;
    cout << "* MSSV: 102190298                               *" << endl;
    cout << "* De so: 05                                     *" << endl;
    cout << "***********************************************" << endl;

    int n = 2014;
    int rc;
    pthread_t threads[n];

    int rs_arr[n];

    for (int i = 1; i <= n; i++)
    {
        int *a = new int;
        *(a) = i - 1;
        rc = pthread_create(&threads[i - 1], nullptr, &xuly, a);
        if (rc)
        {
            cout << "\n Error:" << rc << endl;
            exit(-1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        rc = pthread_join(threads[i - 1], (void **)&rs_arr[i - 1]);
        if (rc)
        {
            cout << "\n Error:!! " << rc << endl;
            exit(-1);
        }
    }

    cout << "\n Tong cac phan tu PT cua moi thread xu ly!! \n";
    for (int i = 0; i < n; i++)
        cout << "Sum thread " << i << " = " << rs_arr[i] << "! \n";
    cout << endl;

    cout << "Tong cac ThreadSum !! \n";
    long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long)rs_arr[i];

    cout << "Result: " << sum << endl;
    pthread_exit(NULL);
}