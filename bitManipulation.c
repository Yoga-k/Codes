#include <stdio.h>

void setBit(int x, int pos)
{
    x = (x|(1<<pos));
    printf("%d ", x); 
}

void clearBit(int x, int pos)
{
    x = (x & (~(1<<pos)));
    printf("%d ", x);
}

void powerTwo(int x)
{
    printf("%d ", (x &&(!(x&(x-1)))));
}

int main()
{
    powerTwo(16);
    setBit(1, 1);
    clearBit(3, 1);
}