#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
  *main - main function or entry point
  *Description: This code tells the last digit
  *Return: (0) always success
  **/
int main(void)
{
	int n;
	int lastdigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastdigit = n % 10;
	if (lastdigit > 5)
	{
		printf("Last digit of %i is %i and is greater than 5\n", n, lastdigit);
	}
	else if (lastdigit == 0)
	{
		printf("Last digit of %i is %i and is 0\n", n, lastdigit);
	}
	else
		printf("Last degit of %i is %i less than 6 and not 0\n", n, lastdigit);
	return (0);
}
