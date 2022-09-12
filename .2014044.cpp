/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-12 02:03:35
 * @LastEditors: Zhao Jiangfeng
 * @LastEditstep: 2022-09-12 02:34:04
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

#define MAX 101

pair<int, int> danger[MAX][MAX];

int n, m, t;
int step = 0;

bool is_avaiable(int x, int y, int step)
{
    if (x > n || y > m || x < 1 || y < 1)
        return false;

    else if (step >= danger[x][y].first && step <= danger[x][y].second)
        return false;
    return true;
}

struct position
{
    int x;
    int y;
    int step;
    position(int x, int y, int t) : x(x), y(y), step(t) {}
};

queue<position> q;

void bfs()
{
    q.push(position(1, 1, 0));
    while (!q.empty())
    {
        position cur_pos = q.front();
        q.pop();
        if (cur_pos.x == n && cur_pos.y == m)
        {
            step = cur_pos.step;
            return;
        }
        if (is_avaiable(cur_pos.x + 1, cur_pos.y, cur_pos.step + 1))
        {
            q.push(position(cur_pos.x + 1, cur_pos.y, cur_pos.step + 1));
        }
        if (is_avaiable(cur_pos.x - 1, cur_pos.y, cur_pos.step + 1))
        {
            q.push(position(cur_pos.x - 1, cur_pos.y, cur_pos.step + 1));
        }
        if (is_avaiable(cur_pos.x, cur_pos.y + 1, cur_pos.step + 1))
        {
            q.push(position(cur_pos.x, cur_pos.y + 1, cur_pos.step + 1));
        }
        if (is_avaiable(cur_pos.x, cur_pos.y - 1, cur_pos.step + 1))
        {
            q.push(position(cur_pos.x, cur_pos.y - 1, cur_pos.step + 1));
        }
    }
}

int main()
{
    IOS;

    cin >> n >> m >> t;
    int r, c, a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> r >> c >> a >> b;
        danger[r][c].first = a;
        danger[r][c].second = b;
    }

    bfs();

    cout << step << endl;
    return 0;
}