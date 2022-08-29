/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-28 21:47:59
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-29 13:45:14
 *
 *
 * 这里对bfs并不熟练，花费了较长的时间，需要进一步练习
 */
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int map[1001][1001] = {0};
bool visited[1001][1001] = {0};
long long total_cost = 0;
int n, m, k, d;
queue<pair<int, int>> q;

void bfs()
{
    int len = m, new_len, level = 0;
    int count = 0;

    while (len > 0)
    {
        new_len = 0;
        for (int l = 0; l < len; l++)
        {
            pair<int, int> this_point = q.front();
            q.pop();
            int x = this_point.first, y = this_point.second;
            if (visited[x][y])
            {
                continue;
            }
            if (map[x][y] > 0)
            {
                total_cost += level * map[x][y];
                count++;
                if (count == k)
                    return;
            }
            visited[x][y] = 1;
            if (x + 1 <= n && !visited[x + 1][y] && map[x + 1][y] != -1)
            {
                q.push(make_pair(x + 1, y));
                new_len++;
            }
            if (y + 1 <= n && !visited[x][y + 1] && map[x][y + 1] != -1)
            {
                q.push(make_pair(x, y + 1));
                new_len++;
            }
            if (x - 1 > 0 && !visited[x - 1][y] && map[x - 1][y] != -1)
            {
                q.push(make_pair(x - 1, y));
                new_len++;
            }
            if (y - 1 > 0 && !visited[x][y - 1] && map[x][y - 1] != -1)
            {
                q.push(make_pair(x, y - 1));
                new_len++;
            }
        }
        len = new_len;
        level++;
    }
}
int main()
{
    cin >> n >> m >> k >> d;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        q.push(make_pair(x, y));
    }

    for (int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        map[x][y] += c;
    }

    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = -1;
    }

    bfs();

    cout << total_cost << endl;
    return 0;
}