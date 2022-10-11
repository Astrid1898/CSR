//
// Created by zhaojiangfeng on 2022/10/11.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;

    int N=31,M=3e5+10;
    int n,x;
    int price[N];
    int f[M];

    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }

    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=M;j>=price[i];j--)
        {
            if(f[j-price[i]])
            {
                f[j]=1;
            }
        }

    }

    int out=x;
    while(1)
    {
        if(f[out]) break;
        else
        {
            out++;
        }
    }

    cout<<out<<endl;

    return 0;
}