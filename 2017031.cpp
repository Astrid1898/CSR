//
// Created by zhaojiangfeng on 2022/11/29.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n, k;
    cin >> n >> k;
    int cnt=0,this_cnt=0,tmp;


    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        this_cnt+=tmp;
        if(this_cnt>=k)
        {
            cnt++;
            this_cnt=0;
        }
    }

    if(this_cnt>0)
        cnt++;

    cout<<cnt<<endl;
    return 0;
}