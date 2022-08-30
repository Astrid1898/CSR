/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-30 02:29:25
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-31 02:08:55
 *
 *
 * 第一次接触状态压缩dp和矩阵的快速幂，代码参考https://www.cnblogs.com/yuhan-blog/p/12308925.html
 * 难度有些大，即使看别人代码也花费了一天时间。
 * 至今不明白为什么输出的是res[0][0]；
 *
 */
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int M = (1 << 7) + 5;

long long n;
int m;
int mm;

int t[M][M];

void dfs(int i, int state, int nex)
{
    if (i == m)
    {
        t[nex][state]++;
        return;
    }

    if (i >= 0 && i < m && ((1 << i) & state))
    {
        dfs(i + 1, state, nex);
    }
    if (i >= 1 && i < m && (!((1 << i) & state)) && (!((1 << i) & nex)) && (!((1 << (i - 1)) & nex)))
        dfs(i + 1, state, nex | (1 << i) | (1 << (i - 1)));

    if (i >= 0 && i < m - 1 && (!((1 << i) & state)) && (!((1 << i) & nex)) && (!((1 << (i + 1)) & nex)))
        dfs(i + 1, state, nex | (1 << i) | (1 << (i + 1)));

    if (i >= 0 && i < m - 1 && (!((1 << i) & state)) && (!((1 << (i + 1)) & state)) && (!((1 << (i + 1)) & nex)))
        dfs(i + 2, state, nex | (1 << (i + 1)));

    if (i >= 0 && i < m - 1 && (!((1 << i) & state)) && (!((1 << (i + 1)) & state)) && (!((1 << i) & nex)))
        dfs(i + 2, state, nex | (1 << i));
}

int temp[M][M];

void multi(int a[][M], int b[][M])
{
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < mm; i++)
    {
        for (int j = 0; j < mm; j++)
        {
            for (int k = 0; k < mm; k++)
                //这里如果没有乘1ll可能会导致结果溢出，只能得40分。
                temp[i][j] = (temp[i][j] + 1ll * a[i][k] * b[k][j] % MOD) % MOD;
        }
    }
    for (int i = 0; i < mm; i++)
        for (int j = 0; j < mm; j++)
            a[i][j] = temp[i][j];
}

int res[M][M];
void Pow(int a[][M], long long n)
{
    for (int i = 0; i < M; i++)
    {
        res[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
            multi(res, a);
        multi(a, a);
        n = n >> 1;
    }
}

int main()
{
    cin >> n >> m;
    mm = (1 << m);
    for (int i = 0; i < mm; i++)
    {
        dfs(0, i, 0);
    }
    Pow(t, n);
    cout << res[0][0];
    return 0;
}