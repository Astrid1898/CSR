//
// Created by zhaojiangfeng on 2022/9/16.
//使用cin和cout也无所谓
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;
    int n;
    cin>>n;
    int nums[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
        sum+=nums[i];
    }

    double average=double(sum)/double(n);
    double d;
    for(int i=0;i<n;i++)
    {
        d+=pow(nums[i]-average,2);
    }
    d=sqrt(d/n);

    for(int i=0;i<n;i++)
    {
        double fa=(double(nums[i])-average)/d;
        cout<<setprecision(16)<<fa<<endl;
    }
    return 0;
}