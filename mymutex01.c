#include <stdio.h>
#define LOOPS 500000
// declare global variable
// type "long long" so that it can accept large numbers
long long sum = 0; 
// declare the function
void MyCounter(int offset);
int main (void)
{
 // count from 0 until 500,000
 MyCounter(1);
 // ...and then decrease until back to 0
 MyCounter(-1);
 // display the output to console
 printf("\nSum is %lld\n", sum);
 return 0;
}
void MyCounter(int offset)
{
 int i = 0;
 for(i=0; i<LOOPS; i++)
 {
 sum = sum + offset;
 printf("Sum is %lld\n", sum);
 }
}
