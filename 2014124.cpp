/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-01 01:27:21
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-01 15:33:30
 *
 *
 * Kruskal即可，注意实现的细节
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct edge
{
    int start;
    int end;
    int cost;
};

bool cmp(const edge &a, const edge &b)
{
    return a.cost < b.cost;
}

int main()
{
    int n, m;

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

    sort(edges, edges + m, cmp);

    long long total_cost = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].start;
        int b = edges[i].end;
        int cost_a_b = edges[i].cost;
        //注意这里必须先将a，b对应的sign取出来再修改，否者会因为顺序出bug
        int a_set = sign[a], b_set = sign[b];
        if (a_set != b_set)
        {
            total_cost += cost_a_b;
            for (int j = 1; j <= n; j++)
            {
                if (sign[j] == b_set)
                    sign[j] = a_set;
            }
        }
    }

    cout << total_cost;
    return 0;
}