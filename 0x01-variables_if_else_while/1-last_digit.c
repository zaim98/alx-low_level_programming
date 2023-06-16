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
	int lstdigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lstdigit = n % 10;
	if (lstdigit > 5)
	{
		printf("Last digit of %i is %i and is greater than 5\n", n, lstdigit);
	}
	else if (lstdigit == 0)
	{
		printf("Last digit of %i is %i and is 0\n", n, lstdigit);
	}
	else
		printf("Last degit of %i is %i and is less than 6 and not 0\n", n, lstdigit);
	return (0);
}
