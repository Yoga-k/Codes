/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
//let say 1234 4321
void palindrome(int num);
int factorial(int num);
int fibonacci(int num);
void strrev(char *str);
void swapByte(int num);
void setBit(int num, int pos);
void clearBit(int num, int pos);
void toggleBit(int num, int pos);
void checkBit(int num, int pos);
void isPoweroftwo(int num);
void notbit(int num);
void reversebits(uint32_t n);

char str[] = "olleh woh";
int main()
{
    palindrome(1234);
    printf("fact of a num is : %d\n", factorial(5));
    printf("fibonacci of a num is : %d\n", fibonacci(5));
    strrev(str);
    swapByte(0xDDCCBBAA);
    setBit(7, 3);
    clearBit(15, 3);
    toggleBit(15, 3);
    toggleBit(7, 3);
    isPoweroftwo(7);
    notbit(15);
    reversebits(15);
    return 0;
}

void palindrome(int num)
{
    int reversed = 0;
    int rem = 0;
    while(num)
    {
        rem = num  % 10;
        num = num / 10;
        reversed  = (reversed * 10) + rem; 
    }
    if( reversed == num)
    {
        printf("The number is palindrome\n");
        return;
    }
    printf("The number is not palindrome\n");
}

int factorial(int num)
{
    if(num == 0)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int fibonacci(int num)
{
    if(num <= 1)
    {
        return num;
    }
    return fibonacci(num-1) + fibonacci(num-2);
}

void strrev(char *str)
{
    printf("The size of the str is : %d\n", strlen(str));
    char *start = str;
    char *end = &str[strlen(str) - 1];
    char temp;
    while(start != end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("The strrev is : %s\n", str);
}

void swapByte(int num)
{
    int swap = ((0xFF000000 & num) >> 24) | ((0x00FF0000 & num) >> 8) | ((0x0000FF00 & num) << 8) | ((0x000000FF & num) <<24);
    printf("swap byte is : 0x%x\n", swap);
}

void setBit(int num, int pos)
{
    int res = num | (1 << pos);
    printf("set bit is: %d\n", res);  
}

void clearBit(int num, int pos)
{
    int res = num & (~(1 << pos));
    printf("clear bit is : %d\n", res);
}

void toggleBit(int num, int pos)
{
    int res = num ^ ( 1<< pos);
    printf("Toggle bit is : %d\n", res);
}

void isPoweroftwo(int num)
{
    printf("power of 2:%d\n", !((num & (num - 1))));
}

void notbit(int num)
{
   printf("power of 2:%d\n", ~num); 
}

void reversebits(uint32_t n)
{
    n = (n >> 16) | (n <<16);
    n = ((n & (0xFF00FF00)) >> 8) | ((n & (0x00FF00FF)) << 8);
    n = ((n & (0xF0F0F0F0)) >> 4) | ((n & (0x0F0F0F0F)) << 4);
    n = ((n & (0xCCCCCCCC)) >> 2) | ((n & (0x33333333)) << 2);
    n = ((n & (0xAAAAAAAA)) >> 1) | ((n & (0x55555555)) << 1);
    printf("Reverse bits are: %d\n", n);
}