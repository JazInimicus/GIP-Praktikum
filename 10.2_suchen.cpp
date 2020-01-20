#include <iostream>
#include "suchen.h"

unsigned int my_strlen(const char* ptr)
{
	int i = 0;
	for (;; i++)
	{
		if (ptr[i] == '\0')
		{
			break;
		}
	}
	return i;
}

int zeichenkette_suchen(const char* text, const char* zkette)
{
	if (zkette[0] == '\0' || text[0] == '\0')
	{
		return -1;
	}
	for (unsigned int i = 0; i < my_strlen(text); i++)
	{
		int j = 0;
		while (zkette[j] != '\0')
		{
			if (text[i + j] != zkette[j])
			{
				break;
			}
			j++;
		}
		if (j == my_strlen(zkette)) //Ausgabe der Position von i, wo die zkette beginnt
		{
			return i;
		}
	}
	return -1;
}
