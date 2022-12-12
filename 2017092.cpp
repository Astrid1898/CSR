//
// Created by zhaojiangfeng on 2022/12/12.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Key
{

    int id;
    int time;
    int status;

    Key(int i, int t, int s)
    {
        id=i;
        time=t;
        status=s;
    }
};

bool cmp(Key& a, Key &b)
{
    return a.time!=b.time?a.time<b.time:a.status!=b.status?a.status>b.status:a.id<b.id;
}

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt","r",stdin);

    int n,k;
    cin>>n>>k;
    vector<int> room(n+1);
    vector<Key> keys;
    for(int i=0;i<=n;i++)
    {
        room[i]=i;
    }

    int w,s,c;
    for(int i=0;i<k;i++)
    {
        cin>>w>>s>>c;
        keys.push_back(Key(w,s,0));
        keys.push_back(Key(w,s+c,1));
    }
    sort(keys.begin(),keys.end(),cmp);

    for(auto it=keys.begin();it!=keys.end();it++)
    {
        if(it->status==0)
        {
            auto it_key=find(room.begin(),room.end(),it->id);
            *it_key=-1;
        }
        else
        {
            auto it_key=find(room.begin(),room.end(),-1);
            *it_key=it->id;
        }

    }

    for(int i=1;i<=n;i++)
    {
        cout<<room[i]<<" ";
    }

    return 0;
}