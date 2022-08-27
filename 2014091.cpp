/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-27 14:24:22
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-27 14:27:11
 */
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int numbers[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(numbers[i] - numbers[j]) == 1)
                count++;
        }
    }
    cout << count;
    return 0;
}