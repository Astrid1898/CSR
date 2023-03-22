//
// Created by zjf on 2023/3/16.
//

//连续走小道疲劳度会累加
/*
 * 非常巧妙的做法，分别用大路和小路两个最短路径，避免了pre的使用
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int MAXN = 100005;


int n, m;
struct Edge
{
    int to, from, t;
    ll w;
} edge[2 * MAXN];

struct node
{
    int u;
    ll d1,d2;
};

ll dist1[MAXN],dist2[MAXN];
int head[2*MAXN];
int cnt;

void add(int t,int u,int v,ll w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].t=t;
    //记录邻接边的下标
    edge[cnt].from=head[u];
    head[u]=cnt++;
}

void spfa(int s)
{
    queue<node> q;
    while(!q.empty())
        q.pop();
    memset(dist1,-1,sizeof(dist1));
    memset(dist2,-1,sizeof(dist2));
    dist1[1]=dist2[1]=0;
    q.push((node){s,0,0});
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        //这里取反只有当i为-1的时候才是false
        for(int i=head[u.u];~i;i=edge[i].from)
        {
            Edge v=edge[i];
            if(v.t==0)
            {
                //d1和d2必有一个为0，取决于最短的线路
                if(dist1[v.to]==-1||dist1[v.to]>=u.d1+v.w+u.d2*u.d2)
                {
                    dist1[v.to]=u.d1+v.w+u.d2*u.d2;
                    q.push(node{v.to,u.d1+v.w+u.d2*u.d2,0});
                }
            }
            else
            {
                if(dist2[v.to]==-1||dist2[v.to]>=u.d1+(v.w+u.d2)*(v.w+u.d2))
                {
                    dist2[v.to]=u.d1+(v.w+u.d2)*(v.w+u.d2);
                    q.push(node{v.to,u.d1,u.d2+v.w});
                }
            }
        }

    }
    if(dist1[n]==-1)
        cout<<dist2[n]<<endl;
    else if(dist2[n]==-1)
        cout<<dist1[n]<<endl;
    else
        cout<<min(dist1[n],dist2[n])<<endl;

}



int main()
{
    IOS;
    freopen("D:\\code\\CODE_C\\C_Single\\CSR\\in.txt", "r", stdin);

    cnt=0;
    memset(head,-1,sizeof (head));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t,a,b;
        ll c;
        cin>>t>>a>>b>>c;
        add(t,a,b,c);
        add(t,b,a,c);
    }

    spfa(1);
    return 0;
}
