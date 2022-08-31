/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-01 01:27:21
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-01 02:28:01
 */
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct edge
{
    int start;
    int end;
    int cost;
    bool operator<(const edge &e) const
    {
        return cost < e.cost;
    }
};

int n, m;

int main()
{

    cin >> n >> m;
    edge edges[m];
    int sign[n + 1];
    for (int i = 1; i <= n; i++)
    {
        sign[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].start >> edges[i].end >> edges[i].cost;
    }

    sort(edges, edges + m);

    long long total_cost = 0;
    set<int> linked;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].start;
        int b = edges[i].end;
        int cost_a_b = edges[i].cost;
        if (sign[a] != sign[b])
        {
            total_cost += cost_a_b;
            for (int j = 1; j <= n; j++)
            {
                if (sign[j] == sign[b])
                    sign[j] = sign[a];
            }
        }
    }
    cout << total_cost;
    return 0;
}