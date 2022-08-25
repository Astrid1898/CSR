/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-07-29 00:46:27
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-07-29 01:07:40
 */
#include <iostream>
using namespace std;

int count[10000] = {0};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        count[s]++;
    }
    int max = 0, max_id = 0;
    for (int i = 1; i < 10000; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            max_id = i;
        }
    }
    cout << max_id;
}