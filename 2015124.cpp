/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-09 02:44:53
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-09 03:10:01
 *
 * dfs找欧拉回路，差点超时
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

#define MAX 10001

bool graph[MAX][MAX];
int n, m;
stack<int> s;

void dfs(int now)
{
    for (int i = 1; i <= n; i++)
    {
        if (graph[now][i])
        {
            graph[now][i] = false;
            graph[i][now] = false;
            dfs(i);
        }
    }
    s.push(now);
}

int main()
{
    IOS;
    memset(graph, 0, sizeof(graph));
    cin >> n >> m;
    int degree[n + 1];
    memset(degree, 0, sizeof(degree));
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        degree[a]++;
        degree[b]++;
    }

    int odd_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] & 1)
        {
            odd_cnt++;
        }
    }

    if (odd_cnt == 0 || (odd_cnt == 2 && (degree[1] & 1)))
    {
        dfs(1);
        if (s.size() - 1 == (unsigned int)m)
        {
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}