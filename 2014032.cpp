/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-24 01:09:38
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-24 16:19:56
 */
#include <iostream>
using namespace std;

struct window
{
    int leftx;
    int lefty;
    int rightx;
    int righty;
};

int main()
{
    int n, m;
    cin >> n >> m;
    struct window windows[n];
    short screen[2560][1440];
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        windows[i - 1].leftx = x1;
        windows[i - 1].lefty = y1;
        windows[i - 1].rightx = x2;
        windows[i - 1].righty = y2;
        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                screen[x][y] = i;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int id = screen[x][y];
        if (id == 0)
            cout << "IGNORED" << endl;
        else
        {
            cout << id << endl;
            for (int x_id = windows[id - 1].leftx; x_id <= windows[id - 1].rightx; x_id++)
            {
                for (int y_id = windows[id - 1].lefty; y_id <= windows[id - 1].righty; y_id++)
                {
                    screen[x_id][y_id] = id;
                }
            }
        }
    }
    return 0;
}