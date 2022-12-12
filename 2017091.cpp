//
// Created by zhaojiangfeng on 2022/12/9.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt","r",stdin);
    int n;

    cin>>n;


    int bottle_5,bottle_3,bottle_1;
    bottle_5=n/50;
    n=n%50;
    bottle_3=n/30;
    n=n%30;
    bottle_1=n/10;

    cout<<bottle_5*7+bottle_3*4+bottle_1<<endl;


    return 0;
}