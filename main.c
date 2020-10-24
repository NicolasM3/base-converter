#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define qtdDigits 36

char digits[qtdDigits] =
  { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
  'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x',
  'y', 'z'
};

void
letterToNumber (char letter)
{
  for (int i = 0; i < qtdDigits; i++)
    {
      if (letter == digits[i])
	{
	  printf ("%c", digits[i]);
	}
    }
}

char
numberToletter (int number)
{
  return digits[number];
}

int
findComma (char number[])
{
  signed int found = -1;
  for (int i = 0; i < 10; i++)
    {
      if (number[i] == '\\')
	break;
      if (number[i] == ',')
	{
	  found = i;
	  break;
	}

    }

  return found;
}

int
main ()
{
  char input_number[10];
  int primary_base, second_base;
  fgets (input_number, 10, stdin);
  scanf ("%d %d", &primary_base, &second_base);

  printf ("%d", findComma (input_number));

  return 0;
}

