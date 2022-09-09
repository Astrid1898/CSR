//
// Created by zhaojiangfeng on 2022/9/8.
//
#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;

    int checkerboard[n][m];
    bool is_erased[n][m];
    memset(checkerboard, 0, sizeof(checkerboard));
    memset(is_erased, 0, sizeof(is_erased));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> checkerboard[i][j];

    for (int i = 0; i < n; i++)
    {
        int j = 0, cnt = 1;
        while (j < m)
        {
            if (cnt < m && checkerboard[i][j] == checkerboard[i][cnt])
            {
                cnt++;
                continue;
            }
            if (cnt - j > 2)
            {
                for (; j < cnt; j++)
                    is_erased[i][j] = true;
            }

            j = cnt;
        }

    }

    for (int j = 0; j < m; j++)
    {
        int i = 0, cnt = 1;
        while (i < n)
        {
            if (cnt < n && checkerboard[i][j] == checkerboard[cnt][j])
            {
                cnt++;
                continue;
            }
            else if (cnt - i > 2)
            {
                for (; i < cnt; i++)
                    is_erased[i][j] = true;
            }

            i = cnt;
        }

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (is_erased[i][j])
                checkerboard[i][j] = 0;
            if (j == 0)
                cout << checkerboard[i][j];
            else
                cout << " " << checkerboard[i][j];
        }

        cout << endl;

    }

    return 0;
}