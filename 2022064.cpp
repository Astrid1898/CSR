/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-19 01:03:23
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-29 02:06:07
 */
#include <bits/stdc++.h>

struct mirror
{
    int x1;
    int x2;
    int y1;
    int y2;
    int id;
};

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{
    IOS;

    freopen("in.txt", "r", stdin);
    vector<mirror> mirrors;

    freopen("CSR/in.txt", "r", stdin);
    int m, id;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> id;
        switch (id)
        {
        case 1:
        {
            int x1, y1, x2, y2 a;
            cin >> x2 >> y1 >> x2 >> y2 >> a;
            break;
        }
        case 2:
        {
            int k;
            cin >> k;
        }
        case 3:
        {
            int x, y, d, i, t;
            cin >> x >> y >> d >> i >> t;
            break;
        }
        }
    }

    return 0;
}