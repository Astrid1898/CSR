/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-27 14:31:47
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-27 14:40:10
 */
#include <iostream>

using namespace std;

int paper[101][101] = {0};

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                if (paper[x][y] == 0)
                {
                    // cout << "x is " << x << ". y is " << y << endl;
                    count++;
                }
                paper[x][y]++;
            }
        }
    }
    cout << count;
    return 0;
}