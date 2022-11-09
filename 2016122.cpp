/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-11-05 19:57:45
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-11-09 21:15:49
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

    freopen("in.txt", "r", stdin);

    int t, salary;
    cin >> t;

    if (t <= 3000)
        salary = t;
    else if (t <= 4955)
    {
        salary = (int)((t - 3000) / 0.03) + 3000;
    }

    cout << salary << endl;
    return 0;
}