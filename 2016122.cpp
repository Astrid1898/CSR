/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-11-05 19:57:45
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-11-09 21:42:59
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main()
{
    IOS;

    freopen("/home/jf-z/codefield/CODE_CPP/Cpp_Single/CSR/in.txt", "r", stdin);

    int t, salary;
    cin >> t;

    if (t <= 3000)
        salary = t;
    else if (t <= 4955)
    {
        salary = (int)((t - 3000) / 0.97) + 3000;
    }
    else if (t <= 7655)
    {
        salary = (int)((t - 4995) / 0.9) + 5000;
    }
    else if (t <= 11255)
    {
        salary = (int)((t - 7655) / 0.8) + 8000;
    }
    else if (t <= 31655)
    {
        salary = (int)((t - 9000) / 0.75) + 12500;
    }

    salary = salary / 100 * 100;
    cout << salary << endl;
    return 0;
}