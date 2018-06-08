// zerovka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>

void zerovka() {
	std::ifstream MFile("input.txt");
	std::ofstream EFile("output.txt");
	std::string number;
	int size = 0;
	long long result = 0;
	std::vector<int> zervec;
	while (getline(MFile, number)) {
		if (std::find(zervec.begin(), zervec.end(),std::stoi(number)) == zervec.end())
		{
			zervec.push_back(std::stoi(number));
		}
	}
	for (auto&item : zervec)
		result += item;
	EFile << std::to_string(result);
	MFile.close();
	EFile.close();
}
int main()
{
	zerovka();
    return 0;
}

