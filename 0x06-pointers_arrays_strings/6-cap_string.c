#include "main.h"

/**
 * *cap_string - Entry
 * Description: This program capitalize words
 * @str: pointer
 * Return: capitalzied string
 */

char *cap_string(char *str)
{
	char seperate[] = ",\t;\n; .!?\"(){}";
	int flg, i, ii;

	for (i = 0; str[i] != '\0'; i++)
	{
		flg = 0;

		if (i == 0)
		{
			flg = 1;
		}
		else
		{
			for (ii = 0; seperate[ii] != '\0'; ii++)
			{
				if (str[i - 1] == seperate[ii])
				{
					flg = 1;
					break;
				}
			}
		}

		if (flg == 1)
		{
			if (str[i] <= 'z' && str[i] >= 'a')
			{
				str[i] -= ('a' - 'A');
			}
		}
	}
	return (str);
}

