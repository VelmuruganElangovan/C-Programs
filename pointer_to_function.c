#include <stdio.h>

int sum(int x, int y)
{
    return x+y;
}

int main( )
{
    int (*fp)(int, int);

    fp = sum;

    int s = fp(10, 15);

    int v = sum(2,5);

    printf("Pointer to function %d\n", s);

    printf("Sum is %d\n", v);

    return 0;


}
