/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-07-31 22:52:58
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-01 00:40:18
 */
#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

void init(int *comb, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
                *(comb + i * size + j) = 1;
            else
                *(comb + i * size + j) = (*(comb + (i - 1) * size + j) + *(comb + (i - 1) * size + (j - 1))) % mod;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int comb[n][n];
    init((int *)comb, n);
    // cout << comb[3][1] << endl;
    int ans = 0;
    for (int k = 2; k <= n - 2; k++)
    {
        ans = (ans + (long long)comb[n - 1][k] * (k - 1) % mod * (n - k - 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}