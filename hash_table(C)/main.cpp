#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> readTree(const std::string &source)
{
    std::ifstream in(source);
    std::string str;
    std::vector<int> result;
    int vecNum = 0;
    if (in.is_open())
    {
        while (getline(in, str))
        {
            vecNum++;
        }
        result = std::vector<int>(static_cast<const unsigned int>(vecNum));
        in.clear();
        in.seekg(0, std::ios::beg);
        auto it = result.begin();
        while (getline(in, str))
        {
            *it = std::stoi(str);
            ++it;
        }
    }
    in.close();
    return result;
}
int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
