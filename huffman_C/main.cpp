#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>


class Node
{
public:
    Node(int frequency, int parents)
    {
        this->frequency = frequency;
        this->parents = parents;
    }

    int frequency = 0;
    int parents = 0;
};

struct CustomCompare
{
    bool operator()(const Node &ln, const Node &rn) const
    {
        return ln.frequency < rn.frequency;
    }
};

int main()
{
    std::ifstream in("huffman.txt");
    std::ofstream out("huffman.out");
    std::string line;
    int dimension = 0;
    int *array = nullptr;
    int index = 0;

    std::cout << in.is_open();
    while (getline(in, line))
    {
        if (index == 0)
        {
            dimension = std::stoi(line);
            array = new int[dimension];
        } else
        {
            std::istringstream lineStream(line);
            std::string item;
            int jndex = 0;
            while (getline(lineStream, item, ' '))
            {
                array[jndex] = std::stoi(item);
                jndex++;
            }
        }
        index++;
    }
    in.close();


    int result = 0;
    std::vector<Node> container;
    container.reserve(dimension);
    auto cmp = [](Node l, Node r)
    { return (l.frequency)^1 < (r.frequency)^1; };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> queue;
    index = 0;

    while (index < dimension)
    {
        queue.push(Node(array[index], array[index]));
        index++;
    }


    index = 0;
    while (index < dimension - 1)
    {
        Node a = queue.top();
        queue.pop();
        Node b = queue.top();
        queue.pop();
        Node c(a.frequency + b.frequency, a.parents + b.parents);
        result += c.parents;
        queue.push(c);
        index++;
    }


    out << result;
    out.close();


    return 0;
}





































