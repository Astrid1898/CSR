//
// Created by zhaojiangfeng on 2023/3/9.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = 1e4 + 10;

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int count = 0, base = 10;
    bool status[N];
    for (int i = 1; i <= n; i++)
        status[i] = true;
    int start = 0;

    while (true)
    {
        for (int i = 1; i <= n; i++)
        {
            if (status[i])
            {
                start++;
                if (start % k == 0 || (start - k) % 10 == 0)
                {
                    status[i] = false;
                    count++;
                }
                //一局比赛里可能会淘汰多人
                if (count == n - 1)
                    break;
            }

        }
        if(count==n-1)
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        if (status[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}