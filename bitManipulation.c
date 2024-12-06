/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void setBit(int x, int pos)
{
    x = (x|(1<<pos));
    printf("Set bit:%d\n", x); 
}

void clearBit(int x, int pos)
{
    x = (x & (~(1<<pos)));
    printf("Clear bit:%d\n", x);
}

void toggleBit(int x, int pos)
{
    x = (x ^ (1<<pos));
    printf("Toggle bit: %d\n", x);
}

void powerTwo(int x)
{
    printf("Check power of two:%d\n", (x &&(!(x&(x-1)))));
}

int showMenu()
{
    int choice = 0;
    printf("1.Check power of two \n");
    printf("2.Set the Bit\n");
    printf("3.Clear the bit\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    do
    {
        choice = showMenu();
        if(choice == 1)
        {
            int val;
            printf("Enter the number: \n");
            scanf("%d", &val);
            powerTwo(val);
        }
        else if(choice == 2)
        {
            pop();
        }
        else if(choice == 3)
        {
            peek();
        }
        
    }while(choice != 4);

}