#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define qtdDigits 36

char digits[qtdDigits] =
  { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
  'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x',
  'y', 'z'
};

int
letterToNumber (char letter)
{
  for (int i = 0; i < qtdDigits; i++)
    {
      if (letter == digits[i])
	return i;
    }
}

char
numberToletter (int number)
{
  return digits[number];
}

int
find (char number[], char charToFind)
{
  signed int found = -1;
  for (int i = 0; i < 10; i++)
    {
      if (number[i] == '\\')
	break;
      if (number[i] == charToFind)
	{
	  found = i;
	  break;
	}

    }

  return found;
}

double
ConvertToDec (char number[], int base)
{
  int commaIndex = find (number, ',');
  int intPart = 0;
  float fractionalPart = 0;
  int mult = -1;
  int lenNumber = strlen (number) - 1;

  if (commaIndex == -1)
    commaIndex = lenNumber ;
  else
    {
      for (int i = commaIndex + 1; i < lenNumber; i++)
	{
	  int decNumber = letterToNumber (number[i]);
	  fractionalPart += decNumber * pow (base, mult);
	  mult--;
	}
      

    }
    mult = 0;

  for (int i = commaIndex - 1; i >= 0; i--)
    {
      int decNumber = letterToNumber (number[i]);
      intPart += decNumber * pow (base, mult);
      mult++;
    }

  return intPart + fractionalPart;
}

int
main ()
{
  char input_number[10];
  int primary_base, second_base;
  fgets (input_number, 10, stdin);
  scanf ("%d %d", &primary_base, &second_base);

  printf ("%lf", ConvertToDec (input_number, primary_base));

  return 0;
}

