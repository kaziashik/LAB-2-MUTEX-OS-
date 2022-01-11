#include <stdio.h>
#include <pthread.h>
#define LOOPS 500000
long long sum = 0; // global variable
void* MyCounter(void *arg);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int main (void)
{
 // create thread 1
 pthread_t id1;
 int offset1 = 1;
 pthread_create(&id1, NULL, MyCounter, &offset1);
 // create thread 2
 pthread_t id2;
 int offset2 = -1;
 pthread_create(&id2, NULL, MyCounter, &offset2);
 // join thread when work is finished
 pthread_join(id1, NULL);
 pthread_join(id2, NULL);
 printf("\nSum is %lld\n", sum);
 return 0;
}
void* MyCounter(void *arg)
{
 int offset = *(int*) arg;
 int i;
 for(i=0; i<LOOPS; i++)
 {
 // start critical section
 pthread_mutex_lock(&mutex);
 sum = sum + offset;
 printf("Sum is %lld\n", sum);
 // stop critical section
 pthread_mutex_unlock(&mutex);
 }
 pthread_exit(NULL);
}
