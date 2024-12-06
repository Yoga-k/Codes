#include <stdio.h>

void powerTwo(int x)
{
    printf("%d ", (x &&(!(x&(x-1)))));
}

int main()
{
    powerTwo(16);
}