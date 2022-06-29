/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-06-26 00:01:08
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-06-27 01:21:39
 */

#include <iostream>
#include <queue>
using namespace std;
int **limits;
int **valid_days;

struct Record
{
    int id1;
    int id2;
    int limit;
    int valid_day;
    bool operator<(const Record &a) const
    {
        return valid_day > a.valid_day;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    limits = new int *[n + 1];
    priority_queue<Record> records;
    for (int i = 0; i <= n; i++)
    {
        limits[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            limits[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            limits[u][v] += x;
            limits[v][u] += x;
            records.push(Record{u, v, x, i + y - 1});
        }
        int l;
        cin >> l;
        while (l--)
        {
            int id, max = 0, max_id = 0;
            cin >> id;
            for (int j = 1; j <= n; j++)
            {
                if (limits[id][j] > max)
                {
                    max = limits[id][j];
                    max_id = j;
                }
            }
            cout << max_id << endl;
        }
        int p, q;
        cin >> p >> q;
        if (p || q)
        {
            int isolate = 0;
            int object[n + 1] = {0};
            for (int j = 1; j <= n; j++)
            {
                int max = 0;
                bool sign = true;
                for (int k = 1; k <= n; k++)
                {
                    if (limits[j][k] > max)
                    {
                        max = limits[j][k];
                        sign = false;
                        object[j] = k;
                    }
                }
                if (sign)
                    isolate++;
            }
            if (p)
                cout << isolate << endl;
            if (q)
            {
                int pair_count = 0;
                for (int j = 1; j <= n; j++)
                {
                    // cout << "object[" << j << "]=" << object[j] << " " << object[object[j]] << endl;
                    if (object[object[j]] == j)
                        pair_count++;
                }
                cout << pair_count / 2 << endl;
            }
        }
        if (!records.empty())
        {
            while (records.top().valid_day == i)
            {
                limits[records.top().id1][records.top().id2] -= records.top().limit;
                limits[records.top().id2][records.top().id1] -= records.top().limit;
                records.pop();
            }
        }
    }
    return 0;
}