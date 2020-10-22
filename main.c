#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define qtdDigits 36

char digits[qtdDigits] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void latterToNumber(char latter)
{
    for(int i = 0; i < qtdDigits; i++)
    {
        if(latter == digits[i])
        {
            printf("%c", digits[i]);
        }
    }
}

char numberToLatter(int number)
{
    return digits[number]; 
}

int main()
{
    char input_number[10];
    int primary_base, second_base;
    gets(input_number);
    scanf("%d %d", &primary_base, &second_base);
    
    return 0;
}



