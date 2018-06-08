#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <set>


using namespace std;
string way = "";
long long n, m;
void rec(vector<pair<long long, long long>> price, long long index);
map<pair<long, long>, long> roads;//дорога и ее номер
set<long long> myRoads;
string forSell = "";
string forBuy = "";
long forBuyCount = 0;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


int main()
{
    freopen("campaign.in", "r", stdin);

    scanf("%lld%lld", &n, &m);

    vector<vector<pair<long long, long long> >> gr(n);
    long long balance = 0;
    vector<long long> cityPrice(n);
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        cityPrice[i] = a;
    }
    vector<long long> roadPrice(m);


    for (long long i = 0; i < m; i++) {
        long long first, second, pravitel, cena;
        scanf("%lld%lld%lld%lld", &first, &second, &pravitel, &cena);
        if (pravitel == 1ll) {
            balance += cena;
            myRoads.insert(i);
        }
        roads.insert(make_pair(make_pair(first - 1, second - 1), i));
        roads.insert(make_pair(make_pair(second - 1, first - 1), i));
        roadPrice[i] = cena;

        gr[first - 1].push_back(make_pair(second - 1, cena + cityPrice[second - 1]));
        gr[second - 1].push_back(make_pair(first - 1, cena + cityPrice[first - 1]));
    }
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


    priority_queue<pair<long long, long long>> pq;//цена и вершина
    vector<pair<long long, long long>> price(n, make_pair(LLONG_MAX, -1));// цена и номер города из которого пришли сюда

    long long s = 0;
    price[0] = make_pair(0, 0);
    pq.push(make_pair(0ll, s));
    while (!pq.empty()) {
        long long from = pq.top().second, c = -pq.top().first;
        pq.pop();

        if (c <= price[from].first)
            for (long long i = 0; i < gr[from].size(); i++) {
                long long relax = c + gr[from][i].second;
                long long to = gr[from][i].first;//city
                if (relax < price[to].first) {
                    pq.push(make_pair(-relax, to));
                    price[to].first = relax;
                    price[to].second = from;
                }
            }
    }
    freopen("campaign.out", "w", stdout);
    //начало формирования ответа
    if (balance >= price[n - 1].first) {
        rec(price, n - 1);
        way=trim(way);

        forBuy = to_string(forBuyCount)+forBuy;

        long long testSum = 0;
        int oneMoreCounter = 0;
        for (auto i = myRoads.begin(); i != myRoads.end()&&testSum<price[n-1].first; i++) {
            forSell += " "+to_string(*i+1) ;
            testSum += roadPrice[*i];
            oneMoreCounter++;
        }
        forSell =to_string(oneMoreCounter) + forSell;
        cout << forSell<<"\n" << forBuy <<"\n"<< way;
    }
    else { cout << to_string(-1ll); }
    return 0;
}
void rec(vector<pair<long long, long long>> price, long long index){
    if (index != 0) {
        pair<long long, long long> tmp = price[index];
        rec(price, tmp.second);
        way = way + " " + to_string(index + 1);
        auto road = roads.find(make_pair(index, tmp.second));
        if (road != roads.end()) {
            if (myRoads.count(road->second)) {
                myRoads.erase(road->second);
            }
            else {
                forBuy = forBuy + " " + to_string(road->second + 1);
                forBuyCount++;
            }
        }

    }
    else {
        way =way + " " + to_string(index+1);
    }
}