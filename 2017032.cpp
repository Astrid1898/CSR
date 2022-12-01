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
    vector<int> queue(n+1);

    for(int i=1;i<=n;i++)
    {
        queue[i]=i;
    }

    int id,operate;

    for(int i=0;i<m;i++)
    {
        cin>>id>>operate;
        vector<int>::iterator it=find(queue.begin(), queue.end(),id);
        queue.erase(it);
        queue.insert(it+operate,id);
    }

    for(int i=1;i<=n;i++)
        cout<<queue[i]<<" ";





    return 0;
}