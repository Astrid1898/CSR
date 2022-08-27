/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-27 00:37:58
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-27 14:20:34
 *
 * 代码来自https://www.itdaan.com/blog/2017/09/24/b37749d0d570f018aba3c5ce94adf645.html
 * 这里使用结构体数组作为dfs使用，颇为新奇。
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 41;
const unsigned int MAXM = 400;
int a[MAXN][5];
int n;
int f[401][401][401];
int p[5][3] = {{2, 2, 2}, {0, 1, 0}, {1, 0, 0}, {0, 3, 3}, {3, 0, 3}};

struct node
{
    int idx, x, y, z;
    node() {}
    node(int idx, int x, int y, int z) : idx(idx), x(x), y(y), z(z) {}
    void out()
    {
        cout << idx << x << y << z << endl;
    }
};
node s[200];

int dfs()
{
    int h = 0;
    s[h++] = node(0, 0, 0, 0);
    f[0][0][0] = -1;
    int i, x, y, z;
    int ans = 233333333;
    while (h != 0)
    {
        node t = s[--h];
        i = t.idx, x = t.x, y = t.y, z = t.z;
        if (f[x][y][z] >= i)
            continue;
        f[x][y][z] = i;

        i++;
        int v = max(x, max(y, z));
        if (v > ans)
            continue;
        if (i == n + 1)
        {
            ans = min(ans, v);
            continue;
        }
        for (int j = 0; j < 5; j++)
        {
            s[h++] = node(i, x + a[i][p[j][0]], y + a[i][p[j][1]], z + a[i][p[j][2]]);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
        if (a[i][2] > a[i][4])
            a[i][2] = a[i][4];
        a[i][0] = 0;
    }
    cout << dfs();
    return 0;
}