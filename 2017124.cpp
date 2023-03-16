//
// Created by zjf on 2023/3/16.
//

//连续走小道疲劳度会累加

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int,int> P;//first边权，second目的顶点编号

int fatigues[502][502],d[502];
bool vis[502]={false};

void dijkstra(int n)
{
    d[1]=0;
    int u,v;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        P p=pq.top();
        pq.pop();
        v=p.second;
        if(d[v]<p.first) continue;
        vis[v]=1;
        for(u=1;u<=n;++u)
        {
            if(!vis[u]&&d[u]>d[v]+fatigues[v][u])
            {
                d[u]=d[v]+fatigues[u][v];
                pq.push(make_pair(d[u],u));
            }
        }
    }
}


int main()
{
    IOS;
    freopen("D:\\code\\CODE_C\\C_Single\\CSR\\in.txt","r",stdin);
    memset(fatigues,0x3f,sizeof(fatigues));
    memset(d,0x3f,sizeof(d));

    int n,m;
    cin>>n>>m;
    int t,a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>t>>a>>b>>c;
        int fatigue=c;
        if(t==1)
            fatigue=c*c;
        if(fatigues[a][b]>fatigue)
        {
            fatigues[a][b]=fatigue;
            fatigues[b][a]=fatigue;
        }
    }
    dijkstra(n);
    cout<<d[n]<<endl;
    return 0;
}
