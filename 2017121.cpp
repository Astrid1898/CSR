//
// Created by zhaojiangfeng on 2023/3/8.
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
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end());
    int min=INT_MAX;
    for(int i=1;i<n;i++)
    {
        int gap=nums[i]-nums[i-1];
        if(gap<min)
            min=gap;
    }
    cout<<min;
    return 0;
}