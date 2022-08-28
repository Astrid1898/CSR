/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-28 21:47:59
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-29 01:50:25
 */
#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001] = {0};
bool visited[1001][1001] = {0};
int cost[1001][1001] = {0};
int n, m, k, d;

void bfs(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    int len = 1, new_len, level = 0;
    int count = 0;

    while (len > 0)
    {
        pair<int, int> this_point = q.front();
        int x = this_point.first, y = this_point.second;
        if (map[x][y] > 0)
        {
            cost[x][y] = max(level * map[x][y], cost[x][y]);
            count++;
            if (count == k)
                return;
        }
        q.pop();
        visited[x][y] = 1;
        if (x + 1 < n && !visited[x + 1][y] && map[x + 1][y] != -1)
            q.push(make_pair(x + 1, y));
        if (y + 1 < n && !visited[x][y + 1] && map[x][y + 1] != -1)
            q.push(make_pair(x, y + 1));
        if (x - 1 > 0 && !visited[x - 1][y] && map[x - 1][y] != -1)
            q.push(make_pair(x - 1, y));
        if (y - 1 > 0 && !visited[x][y - 1] && map[x][y - 1] != -1)
            q.push(make_pair(x, y - 1));
    }
}

int main()
{
    cin >> n >> m >> k >> d;
    int restaurant[m][2];
    int customers[k][3];
    for (int i = 0; i < m; i++)
    {
        cin >> restaurant[i][0] >> restaurant[i][1];
    }

    for (int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        map[x][y] = c;
    }

    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x, y;
        map[x][y] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        bfs(restaurant[i][0], restaurant[i][1]);
    }
    return 0;
}