//
// Created by zhaojiangfeng on 2022/11/30.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n,m;
    cin>>n>>m;
    int queue[n+1],order[n+1];

    for(int i=1;i<=n;i++)
    {
        queue[i]=i;
        order[i]=i;
    }

    int id,operate;

    for(int i=0;i<m;i++)
    {
        cin>>id>>operate;
        int next=order[i]+operate;
        if(next<1)
        {
            next=1;
        }
        else if(next>n)
        {
            next=n;
        }

        order[id]=next;
        int people_to_move=queue[next]




    }





    return 0;
}