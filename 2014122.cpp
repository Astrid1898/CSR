/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-31 13:23:17
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-31 15:31:54
 */
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int matrx[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrx[i][j];
        }
    }

    int count = 0;
    bool go_up = true;
    while (count < 2 * n - 1)
    {
        if (go_up)
        {

            for (int i = count, j = 0; i >= 0; i--, j++)
            {
                if (i >= 0 && i < n && j >= 0 && j < n)
                    cout << matrx[i][j] << " ";
            }
            go_up = false;
        }
        else
        {
            for (int j = count, i = 0; j >= 0; j--, i++)
            {
                if (i >= 0 && i < n && j >= 0 && j < n)
                    cout << matrx[i][j] << " ";
            }
            go_up = true;
        }
        count++;
    }
    return 0;
}