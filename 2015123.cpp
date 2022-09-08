/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-09 00:15:49
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-09 02:15:33
 *
 * 这题目主要难点在于坐标系的转化，第三题大模拟题目一般都在某个
 * 细节上特别复杂，我这里就踩了坑。
 */
//
// Created by zhaojiangfeng on 2022/9/8.
//

#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

#define MAX 100
char canvas[MAX][MAX];
int m, n;

inline bool is_not_wall(char c)
{
    if (c == '|' || c == '-' || c == '+')
        return false;
    else
        return true;
}

void cover(int x, int y, char c)
{
    if (x + 1 < n && is_not_wall(canvas[x + 1][y]) && canvas[x + 1][y] != c)
    {
        canvas[x + 1][y] = c;
        cover(x + 1, y, c);
    }
    if (x - 1 >= 0 && is_not_wall(canvas[x - 1][y]) && canvas[x - 1][y] != c)
    {
        canvas[x - 1][y] = c;
        cover(x - 1, y, c);
    }
    if (y + 1 < m && is_not_wall(canvas[x][y + 1]) && canvas[x][y + 1] != c)
    {
        canvas[x][y + 1] = c;
        cover(x, y + 1, c);
    }
    if (y - 1 >= 0 && is_not_wall(canvas[x][y - 1]) && canvas[x][y - 1] != c)
    {
        canvas[x][y - 1] = c;
        cover(x, y - 1, c);
    }
    return;
}
int main()
{
    IOS;
    int q;
    cin >> m >> n >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            canvas[i][j] = '.';
    }

    int sign;
    while (q--)
    {
        cin >> sign;
        if (sign == 0)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2)
            {
                for (int i = min(y1, y2); i <= max(y1, y2); i++)
                {
                    //这里要注意本身就是拐角处怎么处理，否则只有90分。
                    (canvas[i][x1] == '-' || canvas[i][x1] == '+') ? canvas[i][x1] = '+' : canvas[i][x1] = '|';
                }
            }
            else
            {
                for (int j = min(x1, x2); j <= max(x1, x2); j++)
                {
                    (canvas[y1][j] == '|' || canvas[y1][j] == '+') ? canvas[y1][j] = '+' : canvas[y1][j] = '-';
                }
            }
        }
        else if (sign == 1)
        {
            int x, y;
            char c;
            cin >> x >> y >> c;
            canvas[y][x] = c;

            // x和y弄反了，这里反过来
            cover(y, x, c);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            cout << canvas[i][j];
        }

        cout << endl;
    }

    return 0;
}