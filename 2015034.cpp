/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-04 02:05:50
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-04 14:38:04
 */

#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int n, m;
map<int, vector<int>> graph;
vector<bool> visited;
queue<pair<int, int>> q;
int max_len = 0, max_len_id = 0;

void bfs()
{
    while (!q.empty())
    {
        int cur = q.front().first;
        int len = q.front().second;
        q.pop();
        if (len > max_len)
        {
            max_len = len;
            max_len_id = cur;
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]])
            {
                q.push(make_pair(graph[cur][i], len + 1));
                visited[graph[cur][i]] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int cnt = 2;
    visited = vector<bool>(m + n + 1, false);
    for (int i = 1; i < n + m; i++)
    {
        int tmp;
        cin >> tmp;
        graph[cnt].push_back(tmp);

        graph[tmp].push_back(cnt);
        cnt++;
    }
    visited[1] = true;
    q.push(make_pair(1, 0));
    bfs();

    visited = vector<bool>(m + n + 1, false);
    max_len = 0;
    q.push(make_pair(max_len_id, 0));
    visited[max_len_id] = true;
    bfs();
    cout << max_len << endl;
    return 0;
}