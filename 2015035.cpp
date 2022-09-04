/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-04 14:22:31
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-05 02:00:16
 *
 * 交上去只拿到了10分，空间使用超出。
 * 使用Dijstra算法寻找最短路径，然后用贪心找出最小花费
 * 网上也没有满分的代码，此题暂时搁置
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);
int n, m;

vector<vector<int>> graph;
vector<int> price;
vector<vector<int>> path;
vector<bool> visited;
vector<vector<int>> paths;
vector<int> one_path;

void dijstra(int start, int end)
{
    vector<int> cost(n + 1, INF);
    cost[start] = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = INF, u = -1;
        for (int v = 0; v <= n; v++)
        {
            if (!visited[v] && cost[v] < tmp)
            {
                tmp = cost[v];
                u = v;
            }
        }
        if (u == -1)
            return;

        visited[u] = true;
        for (int j = 1; j < n + 1; j++)
        {
            if (!visited[j] && graph[u][j] != INF)
            {
                if (cost[j] > cost[u] + graph[u][j])
                {
                    cost[j] = cost[u] + graph[u][j];
                    path[j].clear();
                    path[j].push_back(u);
                    continue;
                }
                else if (cost[j] == cost[u] + graph[u][j])
                {
                    path[j].push_back(u);
                }
            }
        }

        int j = 1;
        for (; j <= n; j++)
        {
            if (graph[end][j] != INF)
            {
                if (visited[j] == false)
                    break;
            }
        }
        if (j == n + 1)
            return;
    }
}

void get_paths(int start, int end)
{

    if (end == start)
    {
        one_path.push_back(start);
        reverse(one_path.begin(), one_path.end());
        paths.push_back(one_path);
        one_path.pop_back();
        return;
    }

    one_path.push_back(end);

    for (unsigned int i = 0; i < path[end].size(); i++)
    {
        get_paths(start, path[end][i]);
    }
    one_path.pop_back();
    return;
}

int get_min_cost(int start, int end)
{
    paths.clear();
    get_paths(start, end);
    int min_price = INF;
    for (unsigned int i = 0; i < paths.size(); i++)
    {
        int now = 0, end = paths[i].size() - 1, total_price = 0;
        while (now < end)
        {
            int next_city_to_buy_food = end;
            for (int j = now + 1; j <= end; j++)
            {
                total_price += graph[paths[i][j - 1]][paths[i][j]] * price[paths[i][now]];
                if (price[paths[i][j]] < price[paths[i][now]])
                {
                    next_city_to_buy_food = j;
                    break;
                }
            }
            now = next_city_to_buy_food;
        }
        if (total_price < min_price)
            min_price = total_price;
    }
    return min_price;
}

int main()
{
    IOS;
    cin >> n >> m;
    graph = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    path = vector<vector<int>>(n + 1);
    price = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int start, end, length;
        cin >> start >> end >> length;
        graph[start][end] = length;
        graph[end][start] = length;
    }

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        visited = vector<bool>(n + 1, false);

        dijstra(start, end);
        // get_min_cost(start, end);
        cout << get_min_cost(start, end) << endl;
    }
    return 0;
}