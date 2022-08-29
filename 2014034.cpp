/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-26 21:15:15
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-29 01:53:58
 */
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 210

int n, m, k, r;
bool graph[MAXN][MAXN];
int pos[MAXN][2];
bool visited[MAXN] = {0};

bool is_connected(int i, int j)
{
    return sqrt(pow(pos[i][0] - pos[j][0], 2) +
                pow(pos[i][1] - pos[j][1], 2)) <= r;
}

int bfs(int start, int end)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    int len = 1, new_len, level = 1;
    while (len > 0)
    {
        new_len = 0;
        for (int l = 0; l < len; l++)
        {
            pair<int, int> f = q.front();
            if (f.first == end)
                return level - 2;
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (graph[f.first][i] && !visited[i])
                {
                    q.push(make_pair(i, f.second));
                    visited[i] = true;
                    new_len++;
                }
            }
            for (int i = n; i < m + n; i++)
            {
                if (graph[f.first][i] && !visited[i] && f.second < k)
                {
                    q.push(make_pair(i, f.second + 1));
                    visited[i] = true;
                    new_len++;
                }
            }
        }
        len = new_len;
        level++;
    }
    return -10;
}

int main()
{
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n + m; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
    }
    for (int i = 0; i < n + m; i++)
    {
        for (int j = i + 1; j < n + m; j++)
        {
            graph[i][j] = graph[j][i] = is_connected(i, j);
        }
    }

    cout << bfs(0, 1);
    return 0;
}