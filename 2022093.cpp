//
// Created by zhaojiangfeng on 2022/10/11.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);


    map<int,pair<int,int>> dangerous_area;
    int n;
    cin>>n;
    int d,u,r,ri,mi,pij;
    for(int i=0;i<n;i++)
    {
        for (auto it = dangerous_area.begin(); it != dangerous_area.end();)
        {
            if (it->second.second < i)
            {
                dangerous_area.erase(it++);
            }
            else
            {
                it++;
            }
        }

        cin >> ri >> mi;
        for (int j = 0; j < ri; j++)
        {
            cin >> pij;
            if (dangerous_area.find(pij) != dangerous_area.end())
            {
                dangerous_area[pij].second = i + 6;
            }
            else
            {
                dangerous_area[pij] = make_pair(i, i + 6);
            }

        }
        for(int j=0;j<mi;j++)
        {
            cin>>d>>u>>r;
        }

        cout<<"在第 "<<i<<" 天，高风险地区一共有 "<<dangerous_area.size()<<" 个,分别是:\n";
        for (auto it = dangerous_area.begin(); it != dangerous_area.end(); it++)
        {
            cout<<it->first<<" ";
        }
        cout<<endl;


    }

    return 0;
}