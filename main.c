#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define maxSize 10
#define qtdDigits 36

const char digits[qtdDigits] =
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
         'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
         'u', 'v', 'w', 'x', 'y', 'z'};

int letterToNumber(char letter)
{
    for (int i = 0; i < qtdDigits; i++)
    {
        if (letter == digits[i])
            return i;
    }
    
    return -1;
}

char numberToLetter(int number)
{
    return digits[number];
}

int find(char number[], char charToFind)
{
    signed int found = -1;
    for (int i = 0; i < maxSize; i++)
    {
        if (number[i] == '\\' || number[i] == '\n')
            break;
        if (number[i] == charToFind)
        {
            found = i;
            break;
        }
    }

    return found;
}

char*
ConvertToDec(char number[], int base)
{
    char *ret = malloc (sizeof (char) * maxSize);

    int commaIndex = find(number, ',');
    if (commaIndex == -1)
        commaIndex = find(number, '.');
    int intPart = 0;
    float fractionalPart = 0;
    int mult = -1;
    int lenNumber = strlen(number) - 1;

    if (commaIndex == -1)
        commaIndex = lenNumber;
    else
    {
        for (int i = commaIndex + 1; i < lenNumber; i++)
        {
            int decNumber = letterToNumber(number[i]);
            fractionalPart += decNumber * pow(base, mult);
            mult--;
        }
    }
    mult = 0;

    for (int i = commaIndex - 1; i >= 0; i--)
    {
        int decNumber = letterToNumber(number[i]);
        intPart += decNumber * pow(base, mult);
        mult++;
    }

    double num = (double)(intPart + fractionalPart);

    snprintf(ret, maxSize, "%f", num);

    return ret;
}

char*
ConvertDecToBase(char number[], int base)
{
    char *ret = malloc (sizeof (char) * maxSize);

    int commaIndex = find(number, ',');
    if (commaIndex == -1)
        commaIndex = find(number, '.');
    int intPart = 0;
    float fractionalPart = 0;
    int mult = -1;
    int lenNumber = strlen(number) - 1;

    if (commaIndex == -1)
        commaIndex = lenNumber;
    else
    {
        for (int i = commaIndex + 1; i < lenNumber; i++)
        {
            int decNumber = letterToNumber(number[i]);
            fractionalPart += decNumber * pow(10, mult);
            mult--;
        }
    }
    mult = 0;

    for (int i = commaIndex - 1; i >= 0; i--)
    {
        int decNumber = letterToNumber(number[i]);
        intPart += decNumber * round(pow(10, mult));
        mult++;
    }

    int dividend = intPart;
    char remainder[100];
    int i = 0;
    while (dividend > 0) {
        char cur = numberToLetter(dividend % base);
        remainder[i] = cur;
        dividend /= base;
        i++;
    }

    int j = 0;
    while (i > 0) {
        i--;
        ret[j] = remainder[i];
        j++;
    }
    
    if(fractionalPart != 0) {
        float multiply = fractionalPart;
        ret[j] = ',';
        j++;
        while (multiply != 0.0 && j < 20) {
            char res = numberToLetter(floor(multiply * base));
            ret[j] = res;
            multiply = (multiply * base) - floor(multiply * base);
            j++;
        }
    }
    
    return ret;
}

int main()
{
    char input_number[20];
    int primary_base, second_base, lenNumber;
    char temSinal = '+';
    
    printf("numero:");
    fflush(stdout);
    fgets (input_number, 20, stdin);
    fflush(stdin);
    printf("bases:");
    fflush(stdout);
    scanf ("%d %d", &primary_base, &second_base);
    fflush(stdin);
    
    if(find(input_number,'-') != -1){
        temSinal = '-';
        char* semSinal = input_number + 1;
        memmove(input_number, semSinal, strlen(semSinal) + 1);
    }
    if(primary_base > 36 || second_base > 36)
    {
        printf("Base ou bases invalidas");
        return 0;
    }
    
    lenNumber = strlen(input_number) - 1;
    for(int i = 0; i < lenNumber; i++)
    {
        if(letterToNumber(input_number[i]) == -1 && input_number[i] != ',' && input_number[i] != '.' && input_number[i] != '-')
        {
            printf("Número com caracteres inválido");
            return 0;
        }
    }

    if (primary_base == 10) {
        char* res = ConvertDecToBase(input_number, second_base);
        printf("resultado: %c%s", temSinal, res);
    } else if (second_base == 10) {
        char* res = ConvertToDec(input_number, primary_base);
        printf("resultado: %c%s", temSinal, res);
    } else {
        char* res1 = ConvertToDec(input_number, primary_base);
        char* res2 = ConvertDecToBase(res1, second_base);
        printf("resultado: %c%s", temSinal, res2);
    }

    return 0;
}
