/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-01 14:08:36
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-02 14:39:25
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c;

bool check(int x, int y, bool *visit, char *map)
{
    if (x < 0 || x >= r || y < 0 || y >= c || *(map + x * r + y) == '#' || *(visit + x * r + y))
        return false;
    return true;
}

void dfs1(int x, int y, char *map, bool *start_achiable)
{
    *(start_achiable + x * r + y) = true;
    char t = *(map + x * r + y);
    if (check(x - 1, y, start_achiable, map))
    {
        if ((t == 'S' || t == 'T' || t == '+' || t == '|'))
            dfs1(x - 1, y, map, start_achiable);
    }
    if (check(x + 1, y, start_achiable, map))
    {
        if ((t == 'S' || t == 'T' || t == '+' || t == '|' || t == '.'))
            dfs1(x + 1, y, map, start_achiable);
    }
    if (check(x, y - 1, start_achiable, map))
    {
        if ((t == 'S' || t == 'T' || t == '+' || t == '-'))
            dfs1(x, y - 1, map, start_achiable);
    }
    if (check(x, y + 1, start_achiable, map))
    {
        if ((t == 'S' || t == 'T' || t == '+' || t == '-'))
            dfs1(x, y + 1, map, start_achiable);
    }
    return;
}

void dfs2(int x, int y, char *map, bool *dest_achiable)
{
    *(dest_achiable + x * r + y) = true;
    if (check(x - 1, y, dest_achiable, map))
    {
        char t = *(map + (x - 1) * r + y);
        if ((t == 'S' || t == 'T' || t == '+' || t == '|' || t == '.'))
            dfs2(x - 1, y, map, dest_achiable);
    }
    if (check(x + 1, y, dest_achiable, map))
    {
        char t = *(map + (x + 1) * r + y);
        if ((t == 'S' || t == 'T' || t == '+' || t == '|'))
            dfs2(x + 1, y, map, dest_achiable);
    }
    if (check(x, y - 1, dest_achiable, map))
    {
        char t = *(map + x * r + (y - 1));
        if ((t == 'S' || t == 'T' || t == '+' || t == '-'))
            dfs2(x, y - 1, map, dest_achiable);
    }
    if (check(x, y + 1, dest_achiable, map))
    {
        char t = *(map + x * r + (y + 1));
        if ((t == 'S' || t == 'T' || t == '+' || t == '-'))
            dfs2(x, y + 1, map, dest_achiable);
    }
    return;
}

int main()
{
    cin >> r >> c;
    int start_i, start_j, end_i, end_j;
    char map[r][c];
    bool dest_achivable[r][c];
    bool start_achiable[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                start_i = i;
                start_j = j;
            }
            else if (map[i][j] == 'T')
            {
                end_i = i;
                end_j = j;
            }
            dest_achivable[i][j] = false;
            start_achiable[i][j] = false;
        }
    }

    dfs1(start_i, start_j, (char *)map, (bool *)start_achiable);
    dfs2(end_i, end_j, (char *)map, (bool *)dest_achivable);

    int count = 0;
    if (!start_achiable[end_i][end_j])
    {
        cout << "I'm stuck!" << endl;
        return 0;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!(dest_achivable[i][j]) && start_achiable[i][j] && map[i][j] != 'S' && map[i][j] != 'T')
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}