#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

void allocate_other_matrices();

void read_villages_from_file();

void prepare_matrix();

void main_part();

long long calculate_dist(int left_border, int right_border);

long long complete_stuff();

using namespace std;
unsigned int dimension = 0;
unsigned int stations_num = 0;
long long coordinates[2000];
long long matrix[30][2000];
long long dist_mat[2000][2000];

int main()
{
    read_villages_from_file();
    allocate_other_matrices();
    prepare_matrix();
    main_part();
    ofstream out("out.txt");
    out << complete_stuff();
    out.close();
    return 0;
}

long long complete_stuff()
{
    long long result = matrix[stations_num - 1][dimension - 1];
    for (int i = stations_num - 1; i < dimension; i++)
    {
        for (int j = i; j < dimension; j++)
        {
            matrix[stations_num - 1][i] += abs(coordinates[j] - coordinates[i]);
        }
        result = min(result, matrix[stations_num - 1][i]);
    }
    return result;
}

void main_part()
{
    long long _min = LLONG_MAX;
    for (int i = 1; i < stations_num; i++)
    {
        for (int j = i; j <= dimension - stations_num + i; j++)
        {
            _min = LLONG_MAX;
            for (int k = j; k >= i; k--)
            {
                _min = min(_min, calculate_dist(k - 1, j) + matrix[i - 1][k - 1]);
            }
            matrix[i][j] = _min;
        }
    }
}

long long calculate_dist(int left_border, int right_border)
{

    if (dist_mat[left_border][right_border] == -1)
    {
        long long median = round((coordinates[right_border] + coordinates[left_border]) / 2.);

        long long distance = 0;
        for (int i = left_border + 1; i < right_border; i++)
            if (coordinates[i] <= median)
            {
                distance += abs(coordinates[i] - coordinates[left_border]);
            } else
            {
                distance += abs(coordinates[right_border] - coordinates[i]);
            }
        dist_mat[left_border][right_border] = distance;
    }
    else{
        cout << "*";
    }
    return dist_mat[left_border][right_border];
}

void prepare_matrix()
{
    for (int i = 0; i <= dimension - stations_num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            matrix[0][i] += abs(coordinates[i] - coordinates[j]);
        }
    }
}

void allocate_other_matrices()
{
    for (int i = 0; i < stations_num; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            dist_mat[i][j] = -1;
        }
    }
}

void read_villages_from_file()
{
    ifstream in("in.txt");
    string line;
    unsigned int i = 0;
    while (getline(in, line))
    {
        stringstream ss(line);
        string token;
        if (i == 0)
        {
            getline(ss, token, ' ');
            dimension = static_cast<unsigned int>(stoi(token));
            getline(ss, token, ' ');
            stations_num = static_cast<unsigned int>(stoi(token));
        } else
        {
            int index = 0;
            while (getline(ss, token, ' '))
            {
                coordinates[index] = stoi(token);
                index++;
            }
        }
        i++;
    }
    in.close();
}
