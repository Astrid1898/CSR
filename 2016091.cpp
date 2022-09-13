/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-13 01:48:36
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-13 01:53:52
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{
    IOS;
    int n;
    cin >> n;
    int pre, now;
    int max = 0;

    cin >> pre;

    for (int i = 1; i < n; i++)
    {
        cin >> now;
        if (abs(now - pre) > max)
            max = abs(now - pre);
        pre=now;
    }
    cout << max << endl;

    return 0;
}