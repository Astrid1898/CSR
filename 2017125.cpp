//
// Created by zhaojiangfeng on 2023/3/16.
//

/*
 * 本以为是一道遍历剪枝然后升级为状态压缩dp的题目，没想到是拓扑排序
 * 从题目给的直接上级只有一个那里应该可以想到树状结构，用队列去做
 */


#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;

const int N = 1e5 + 1;

int n;
unsigned long long limit = 10e18;
queue<int> q;
ll v[N], f[N], u[N], s[N];
ll ans[N];

//保存直接下级点城市的数量
int next_num[N] = {0};

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> u[j] >> s[j] >> v[j] >> f[j];
            next_num[u[j]]++;
        }


        //先找出直接下级数量为0的城市，使其入队
        for (int j = 1; j <= n; j++)
        {
            if (!next_num[j])
                q.push(j);
        }

        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            int pre = u[k], d = s[k];
            next_num[pre]--;
            //如果所有的直接下级城市都已经处理过了，则将该城市入队
            if (!next_num[pre])
                q.push(pre);

            //寻找所有上级，计算上级城市到这里的获利
            while(pre)
            {
                ans[pre]=max(ans[pre],(ans[k]+v[pre]-(f[pre]-d)*(f[pre]-d)));
                d+=s[pre];
                pre=u[pre];
            }

        }


        unsigned long long total_value = 0;

        for (int j = 1; j <= n; j++)
        {
            total_value = (total_value + ans[j]) % limit;
            ans[j]=0;
            next_num[j]=0;
        }
        cout << total_value << endl;
    }
}


