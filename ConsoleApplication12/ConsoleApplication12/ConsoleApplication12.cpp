// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

char *makeUpperCase(char *string)
{
	int i = 0;
	int length = strlen(string);
	while (i < length)
	{
		std::cout <<(char)((int)(string[i]) - 32);
		i++;
	}
	return string;
};

int main()
{
	std::cout << makeUpperCase("abc");
	system("pause");
    return 0;
}

