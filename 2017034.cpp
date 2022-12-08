//
// Created by zhaojiangfeng on 2022/12/6.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct Edge
{
    int u, v;
    int weight;

    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}

    friend bool operator>(const struct Edge &e1, const struct Edge e2);
};

inline bool operator>(const struct Edge &e1, const struct Edge e2)
{
    return e1.weight > e2.weight;
}

vector<int> father, result;


//直接使用while循环会导致超时，所以这里使用递归，若a不是根节点，则每次查询将其父节点更改为根节点
int find_father(int a)
{
    if(a==father[a])
        return a;
    else
    {
        father[a] = find_father(father[a]);
        return father[a];
    }
}


int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    father.resize(n + 1);

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;


    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push(Edge(u, v, w));
    }


    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }

    while (find_father(1) != find_father(n))
    {
        Edge tmp = pq.top();
        pq.pop();
        int u = tmp.u;
        int v = tmp.v;
        result.push_back(tmp.weight);
        father[find_father(u)] = father[find_father(v)];

    }

    cout<<result[result.size()-1]<<endl;

    return 0;
}