/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-03 00:28:33
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-04 02:04:40
 */
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)

int main()

{
    int n, m;
    cin >> n >> m;
    int pic[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pic[i][j];

    for (int j = 1; j <= m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << " ";
            cout << pic[i][m - j];
        }
        cout << endl;
    }

    return 0;
}