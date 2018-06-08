// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
int unusual_five()
{
	return 'd'^'a';
}

int main()
{
	printf("%d", unusual_five());
	system("pause");
    return 0;
}

