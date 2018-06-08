#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

long long dp[30][2000];
long long village[2000];
long long distances_r[2000][2000];
long long v, p;

long long function_distances(long long index_begin, long long index_end)
{
    if (distances_r[index_begin][index_end] == -1)
    {
        long long distance = 0;
        long long median;
        if (v > 1000)
        {
            median = round((village[index_end] + village[index_begin]) / 2.);
        } else
        {
            median = round((village[index_end] + village[index_begin]) / 2);
        }
        for (long long i = index_begin + 1; i < index_end; i++)
        {
            if (village[i] <= median)
            {
                distance += abs(village[i] - village[index_begin]);
            } else
            {
                distance += abs(village[index_end] - village[i]);
            }
        }
        distances_r[index_begin][index_end] = distance;
    }
    return distances_r[index_begin][index_end];
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    long long ans;
    in >> v >> p;
    for (long long i = 0; i < p; i++)
    {
        for (long long j = 0; j < v; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (long long i = 0; i < v; ++i)
    {
        in >> village[i];
    }
    for (long long i = 0; i < v; ++i)
    {
        for (long long j = 0; j < v; j++)
        {
            distances_r[i][j] = -1;
        }
    }
    long long k = 2;
    dp[p - 1][v - 1] = 0;
    for (long long i = v - k; i >= p - 1; i--)
    {
        for (long long j = 1; j < k; j++)
        {
            dp[p - 1][i] += abs(village[v - j] - village[v - k]);
        }
        k++;
    }

    for (long long i = p - 2; i >= 0; i--)
    {
        for (long long j = v - (p - i); j >= i; j--)
        {
            long long minimum = 1E9;
            for (long long l = j; l <= v - (p - i); l++)
            {
                minimum = min(minimum, function_distances(j, l + 1) + dp[i + 1][l + 1]);
            }
            dp[i][j] = minimum;
        }
    }

    ans = dp[0][0];
    for (long long i = v - 1 - (p - 1); i >= 1; i--)
    {
        for (long long j = 0; j <= i - 1; j++)
        {
            dp[0][i] += abs(village[i] - village[j]);
        }
        if (dp[0][i] < ans)
        {
            ans = dp[0][i];
        }
    }

    out << ans;
    return 0;
}