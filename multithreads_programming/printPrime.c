#include <pthread.h>
#include <stdio.h>
/*Hàm tính toán trả về số nguyên tố thứ n, n là là giá trị được trỏ bởi 
*arg. */
void *compute_prime(void *arg)
{
    int pri = 2;
    int n = *((int *)arg);
    while (1)
    {
        int i;
        int nguyento = 1;
        for (i = 2; i < pri; ++i)
            if (pri % i == 0)
            {
                nguyento = 0;
                break;
            }
        if (nguyento)
        {
            if (--n == 0)
                return (void *)pri;
        }
        ++pri;
    }
    return NULL;
}
int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);
    pthread_t threads[20]; 

    for (int i = 1; i <= n; i++) 
    { 
        int prime;
        /* Bắt đầu luồng tính toán số nguyên tố thứ  n. */
        pthread_create(&threads[i], NULL, &compute_prime, &i);
        /* Chờ luồng tính số nguyên tố hoàn thành, và lấy kết quả trả về.*/
        pthread_join(threads[i], (void *)&prime);
        /* In ra số nguyên tố thứ n. */
        printf("So nguyen to thu  %d la  %d. Dang duoc xu ly boi luong %d.\n", i, prime, (int)pthread_self());
    }


    pthread_exit(NULL);
    return 0;
}