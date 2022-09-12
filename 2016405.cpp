/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-12 22:38:37
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-13 01:47:11
 *
 * 无思路，也无答案，放一个网上看到的版本。
 */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define INF 3000

long long ans = 0;
struct Edge //边的结构体
{
    int a, b, cost;   //(a,b)边的权cost
} edge[100000 + 100]; //边的集合，等会用于排序
int parent[500 + 5];  //并查集，将每个联通分量都用最上方的根表示

struct Node
{
    bool flag = false;
    int num = 0, l = 0, poi = 0;
    int next[550], cost[550];
} node[550];

bool com(Edge a, Edge b)
{
    return a.cost < b.cost;
}

void init() //初始化parent数组
{
    for (int i = 0; i <= 500 + 5; i++)
    {
        node[i].poi = 0;
        node[i].flag = false;
        parent[i] = i;
    }
}
int find(int x)
{
    int r = x;
    while (r != parent[r]) //寻找根结点
        r = parent[r];
    int i = x, j;  // i是最底层，j是从i往根处爬，
    while (i != r) //压缩路径  将i结点直接连着根，j为i结点之前的父亲
    {
        j = parent[i]; // j为i结点之前的父亲
        parent[i] = r;
        i = j; //重新对i结点（此时为前一个i结点的父亲） 做压缩路劲
    }          //最终所有的结点都有共同的父亲，共同的根，一个根连着很多直系儿子
    return r;
}
int Union(int a, int b) //连接两个连通分量 a和 b
{
    int x = find(a);
    int y = find(b);
    if (x != y) //如果a和b不是同一个连通分量则把其中一个联通分量的根认另一个联通分量的根为根（老大）
    {
        parent[x] = y;
        return 1;
    }
    return 0;
}

bool vis[550] = {false};
bool DFS(int num)
{
    if (vis[num])
        return false;
    vis[num] = true;
    bool res = false;
    for (int i = 0; i < node[num].l; i++)
    {
        int k = node[num].next[i], t;
        if (DFS(k))
        {
            res = true;
            ans += node[num].cost[i];
        }
    }
    if (node[num].flag)
        res = true;
    vis[num] = false;
    //    if(res) cout << node[num].num << endl;
    return res;
}

int main()
{
    int T, n, m, p, num;
    cin >> T;
    while (T--)
    {
        init();
        cin >> n >> m >> p;
        getchar();
        for (int i = 0; i < n; i++)
        {
            char c;
            c = getchar();
            if (c == '1')
                node[i + 1].flag = true, num = i + 1;
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edge[i].a = u;
            edge[i].b = v;
            edge[i].cost = w;
        }
        sort(edge, edge + m, com);

        for (int i = 0; i < m; i++)
        {
            int beg = edge[i].a, end = edge[i].b;
            //            cout << beg << ' ' <<end << endl;
            if (Union(beg, end)) //如果边的两个顶点不是同一个连通分量则为我们选定的边
            {
                //                cout << beg << ' ' << end << endl;
                node[beg].next[node[beg].poi] = end;
                node[end].next[node[end].poi] = beg;
                node[beg].cost[node[beg].poi] = edge[i].cost;
                node[end].cost[node[end].poi] = edge[i].cost;
                node[end].poi++;
                node[beg].poi++;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            node[i].num = i;
            node[i].l = node[i].poi;
        }
        //        cout << num << endl;
        DFS(num);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
