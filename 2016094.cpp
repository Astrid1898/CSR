/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-16 00:35:33
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-16 02:31:24
 *
 * 一开始以为是一个distra找到候选的路径，然后在路径上
 * 找到最小生成树，结果发现这个思路并不对。
 * 这里如果采用邻接矩阵的方式存储图的时候，内存会超出限制，
 * 需要用vector保存。另外，需要最小堆优化。
 */
//
// Created by zhaojiangfeng on 2022/9/15.
//

#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int n, m;

#define MAXN 10005
#define min(a, b) (a) < (b) ? (a) : (b)

struct node
{
    int v, len;
    node(int v = 0, int len = 0) : v(v), len(len) {}
    //我们需要的是最小堆，所以这里将符号定义相反。
    bool operator<(const node &a) const
    {
        return len > a.len;
    }
};

bool visited[MAXN];
int cost[MAXN];

vector<node> G[MAXN];
int total = 0;

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        G[i].clear();
        cost[i] = INT_MAX;
    }
}

void dijstra()
{
    priority_queue<node> q;
    q.push(node(1, 0));
    int dis[n + 1];
    for (int i = 0; i < n + 1; i++)
        dis[i] = INT_MAX;
    dis[1] = 0;

    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        int u = now.v;
        if (visited[u])
            continue;
        visited[u] = true;

        for (unsigned int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i].v;
            int len = G[u][i].len;

            if (!visited[v] && dis[v] > dis[u] + len)
            {
                dis[v] = dis[u] + len;
                cost[v] = len;
                q.push(node(v, dis[v]));
            }
            else if (dis[v] == dis[u] + len)
            {
                cost[v] = min(cost[v], len);
            }
        }
    }
}

int main()
{
    IOS;

    memset(visited, 0, sizeof(visited));
    cin >> n >> m;

    int x, y, l;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> l;
        G[x].push_back(node(y, l));
        G[y].push_back(node(x, l));
    }

    dijstra();

    for (int i = 2; i <= n; i++)
    {
        total += cost[i];
    }
    cout << total;
    return 0;
}