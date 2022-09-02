/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-02 02:11:59
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-02 19:59:46
 *
 *
 * 这道题目比较复杂，参考https://blog.csdn.net/qq_41418281/article/details/104007018做法
 * 这里有几个需要需注意点：
 * 1）把生产消耗运输存储问题转化为了统一的最小消耗最大流问题，让人叹服。
 * 2）把一周七天当做七个节点，首尾相互连接。
 * 3）生产当做从源节点无穷带宽无成本流向，消耗当做向目的节点无穷带宽无成本流出
 * 4）zwk算法，这个看了好久
 */
#include <iostream>
#include <string.h>
#include <deque>

using namespace std;

#define IOS ios::sync_with_stdio(false)
#define maxn 805
#define maxm 50005
#define INF 200000005
#define ll long long

struct ZKW
{
    int s, t, n;
    int cost;
    bool vis[maxn];
    int dist[maxn];

    int nedge, p[maxm], c[maxm], costs[maxm], nex[maxm], head[maxn];

    void add_edge(int x, int y, int z, int cost)
    {
        p[++nedge] = y, c[nedge] = z, costs[nedge] = cost, nex[nedge] = head[x], head[x] = nedge;
        p[++nedge] = x, c[nedge] = 0, costs[nedge] = -cost, nex[nedge] = head[y], head[y] = nedge;
    }

    void init(int n, int s, int t)
    {
        this->n = n, this->s = s, this->t = t;
        memset(nex, -1, sizeof(nex));
        memset(head, -1, sizeof(head));
        cost = 0, nedge = -1;
    }

    bool spfa(int s, int t)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= n; i++)
            dist[i] = INF;
        dist[t] = 0;
        vis[t] = 1;
        deque<int> q;
        q.push_back(t);
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            for (int k = head[now]; k > -1; k = nex[k])
            {
                if (c[k ^ 1] && dist[p[k]] > dist[now] - costs[k])
                {
                    dist[p[k]] = dist[now] - costs[k];
                    if (!vis[p[k]])
                    {
                        vis[p[k]] = 1;
                        if (!q.empty() && dist[p[k]] < dist[q.front()])
                            q.push_front(p[k]);
                        else
                            q.push_back(p[k]);
                    }
                }
            }
            vis[now] = 0;
        }
        return dist[s] < INF;
    }

    int dfs(int x, int low)
    {
        if (x == t)
        {
            vis[t] = 1;
            return low;
        }
        int used = 0, a;
        vis[x] = 1;

        for (int k = head[x]; k > -1; k = nex[k])
        {
            if (!vis[p[k]] && c[k] && dist[x] - costs[k] == dist[p[k]])
            {
                a = dfs(p[k], min(c[k], low - used));
                if (a)
                {
                    cost += a * costs[k];
                    c[k] -= a;
                    c[k ^ 1] += a;
                    used += a;
                }
                if (used == low)
                    break;
            }
        }
        return used;
    }

    int costflow()
    {
        int flow = 0;
        while (spfa(s, t))
        {
            vis[t] = 1;
            while (vis[t])
            {
                memset(vis, 0, sizeof(vis));
                flow += dfs(s, INF);
            }
        }
        return flow;
    }
} G;

int main()
{

    int n, m;
    cin >> n >> m;
    int st = 0;
    int ed = n * 7 + 2;
    G.init(7 * n + 5, st, ed);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            int x;
            cin >> x;
            G.add_edge(st, (i - 1) * 7 + j, x, 0);
        }

        for (int j = 1; j <= 7; j++)
        {
            int x;
            cin >> x;
            G.add_edge((i - 1) * 7 + j, ed, x, 0);
        }

        int v, w;
        cin >> v >> w;
        for (int j = 1; j <= 6; j++)
        {
            G.add_edge((i - 1) * 7 + j, (i - 1) * 7 + j + 1, v, w);
        }
        //一周结束后可以囤积到下一周
        G.add_edge((i - 1) * 7 + 7, (i - 1) * 7 + 1, v, w);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = 1; i <= 7; i++)
        {
            G.add_edge((x - 1) * 7 + i, (y - 1) * 7 + i, INF, z);
            G.add_edge((y - 1) * 7 + i, (x - 1) * 7 + i, INF, z);
        }
    }
    G.costflow();
    cout << G.cost;
    return 0;
}