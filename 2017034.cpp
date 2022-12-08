//
// Created by zhaojiangfeng on 2022/12/6.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct Edge
{
    int u,v;
    int weight;
    Edge(int u,int v,int w):u(u),v(v),weight(w){}
    friend bool operator > (const struct Edge &e1,const struct  Edge e2);
};

inline bool operator > (const struct Edge &e1,const struct  Edge e2)
{
    return e1.weight>e2.weight;
}


int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n,m;
    cin>>n>>m;
    vector<int> father(n+1);
    vector<int> result(n+1);

    priority_queue<Edge,vector<Edge>,greater<Edge>> pq;


    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pq.push(Edge(u,v,w));
    }


    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }

    for(int i=0;i<pq.size()&&result.size()<=n-1;i++)
    {
        int u=
    }




    return 0;
}