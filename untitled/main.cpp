#include <iostream>
#include <ctime>

int main()
{
    auto *mass = new int[1];
    mass[0] = 4;
    double start = clock();
    for(int i = 0; i < 100000000; i++)
    {
        mass[0];
    }
    std::cout << "time 1 = " << (clock() - start)/1000 << std:: endl;
    start = clock();
    int temp = mass[0];
    for(int i = 0; i < 100000000; i++)
    {
        temp;
    }
    std::cout << "time 2 = " << (clock() - start)/1000 << std:: endl;
    std::system("pause");
    return 0;
}