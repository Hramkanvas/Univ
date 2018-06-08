#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int dimension = 0;
int matrix[1000][1000];
void read_villages_from_file()
{
    ifstream in("input.in");
    string line;
    unsigned int i = 0;
    while (getline(in, line))
    {
        stringstream ss(line);
        string token;
        if (i == 0)
        {
            dimension = static_cast<unsigned int>(stoi(line));
        } else
        {
            int index = 0;
            while (getline(ss, token, ' '))
            {

                matrix[i - 1][index] = stoi(token);
                index++;
            }
        }
        i++;
    }
    in.close();
}

int main()
{
    read_villages_from_file();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}