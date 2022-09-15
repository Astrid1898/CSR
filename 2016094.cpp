//
// Created by zhaojiangfeng on 2022/9/15.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m;

#define MAXN 10005


struct edge
{
    int x, y,len;
    edge(int s,int d, int l)
    {
        x=s;
        y=d;
        len=l;
    }

};
vector<edge> edges;

bool visited[MAXN];
vector<vector<int>> pre;

int graph[MAXN][MAXN];

bool cmp(edge &a, edge &b)
{
    return a.len < b.len;
}


void dijstra()
{
    int dis[n + 1];
    for(int i=0;i<n+1;i++)
        dis[i]=INT_MAX;
    dis[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int min = INT_MAX;
        int u=-1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dis[j] < min)
            {
                min=dis[j];
                u=j;
            }
        }
        if(u==-1) break;
        visited[u]=true;

        for(int v=1;v<=n;v++)
        {
            if(!visited[v]&&graph[u][v]!=0)
            {
                if(dis[v]>dis[u]+graph[u][v])
                {
                    dis[v]=dis[u]+graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v]==dis[u]+graph[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }

    }

}
void prime()
{

}


int main()
{
    IOS;

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;

    pre.resize(n + 1);

    int x, y, l;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> l;
        graph[x][y] = l;
        graph[y][x] = l;
    }

    dijstra();
    memset(visited, 0, sizeof(visited));
    for(int i=1;i<pre.size();i++)
    {
        for(int j=0;j<pre[i].size();j++)
        {
            edges.push_back(edge(i,j,graph[i][j]));
        }
    }
    sort(edges.begin(),edges.end(),cmp);

    prime()
    return 0;
}