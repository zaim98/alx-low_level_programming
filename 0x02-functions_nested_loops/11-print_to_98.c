#include "main.h"
/**
  *print_to_98 - Entry point
  *Description:Numbers must be separated by a comma, followed by a space
  *Numbers should be printed in order
  *The first printed number should be the number passed to your function
  *The last printed number should be 98
  *@n: counting begins here
  */
void print_to_98(int n)
{
	if (n >= 98)
	{
		while (n > 98)
		{
			printf("%d, ", n--);
		}
		printf("%d\n", n);
	}
	else
	{
		while (n < 98)
		{
			printf("%d, ", n++);
		}
		printf("%d\n", n);
	}
}
