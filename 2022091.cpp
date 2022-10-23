/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-10-11 01:01:35
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-10-23 22:27:25
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{

    IOS;

    //    freopen("/home/szu/CLionProjects/untitled/in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    int c[n + 1];
    c[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = c[i - 1] * a[i];
    }

    int m_mod_c = 0;
    int b;
    for (int i = 1; i <= n; i++)
    {
        m_mod_c = m % c[i] - m_mod_c;
        b = m_mod_c / c[i - 1];
        cout << b << " ";
    }
}