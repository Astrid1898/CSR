/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-10-29 20:42:56
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-10-30 21:55:51
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    map<int,int> num_count;

    int n,tmp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        num_count[tmp]++;
    }

    int before=0,sign=0;

    for(auto it=num_count.begin();it!=num_count.end();it++)
    {
        if(n-it->second-before==before)
        {
            sign=1;
            cout<<it->first;
            break;
        }
        before+=it->second;
    }

    if(sign==0)
        cout<<-1;



    return 0;
}