// trenirivkasobektami.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
class Moy {
public:
	Moy*down = NULL;
	int* key = NULL;
};

int main()
{
	Moy cl1;
	int k1 = 1, k2 = 2, k3 = 3;
	cl1.key = &k1;
	cl1.down = new Moy();
	(cl1.down)->key = &k2;
	cl1 = *cl1.down;
	delete cl1.down;
	std::cout << *cl1.key;
	std::system("pause");
	return 0;
}

