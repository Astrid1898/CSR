/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-06-01 01:06:19
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-06-01 01:53:03
 */

#include <iostream>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long diffArray[200005] = {0};
    while (n--)
    {
        long long t, c;
        cin >> t >> c;
        diffArray[t - c < 0 ? 1 : (t - c + 1)]++;
        diffArray[t + 1]--;
    }
    for (int i = 1; i < 200005; i++)
        diffArray[i] += diffArray[i - 1];

    while (m--)
    {
        long long q;
        cin >> q;
        if (q + k >= 200005)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << diffArray[q + k] << endl;
        }
    }
    return 0;
}