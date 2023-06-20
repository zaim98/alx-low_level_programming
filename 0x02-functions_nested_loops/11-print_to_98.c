#include "main.h"
#include <stdio.h>
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
	int tir;

	if (n > 98)
		for (tir = n; tir > 98; tir--)
			printf("%d, ", tir);
	else
		for (tir = n; tir < 98; tir++)
			printf("%d , ", tir);
	printf("\n");
}
