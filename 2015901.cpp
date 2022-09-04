/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-05 02:02:51
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-05 02:05:54
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{
    int n, now, cnt = 0;
    cin >> n;
    cin >> now;
    for (int i = 1; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp != now)
        {
            now = tmp;
            cnt++;
        }
    }
    cout << ++cnt;
    return 0;
}