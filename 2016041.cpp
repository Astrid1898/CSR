/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-10 02:06:18
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-10 02:13:55
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{
    IOS;
    int n, cnt = 0, sign = 0, a, last;
    cin >> n;
    cin >> last;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a > last)
        {
            if (sign < 0)
            {
                cnt++;
                sign = 1;
            }
            else
                sign = 1;
        }
        else
        {
            if (sign > 0)
            {
                cnt++;
                sign = -1;
            }
            else
                sign = -1;
        }
        last = a;
    }
    cout << cnt;
    return 0;
}